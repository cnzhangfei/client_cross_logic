#ifndef __TEST_SUITE__
#define __TEST_SUITE__

#include <cstdlib>
#include <string>
#include <iostream>
#include "special_client.hpp"

enum {
    test_version = 0,
    nets_version,
    bblc_version,
    bblm_version
};

namespace marshal {

    template <class T>
    struct action<T, nets_version, gui_command> {
        typedef action_imp<T, nets_version> imp_action;

        enum {
            id = gui_command
        };

        template <int Source>
        void on(const place_holder<Source> &) {
            const char *const view_name = information<Source, gui_command, nets_version>::name();
            std::cout << "nets will be excute gui -->" << view_name << std::endl;
        }
    };

    template <class T>
    struct action<T, bblc_version, gui_command> {
        typedef action_imp<T, nets_version> imp_action;

        enum {
            id = gui_command
        };

        template <int Source>
        void on(const place_holder<Source> &) {
            const char *const view_name = information<Source, gui_command, nets_version>::name();
            std::cout << "bblc will be excute gui -->" << view_name << std::endl;
        }
    };
}

namespace marshal {

    template <int version>
    void test_client() {
        std::cout << "-----------------" << version << " beg -------------" << std::endl;
        w_client_pub<version> w_client;
        int cmd_list[] = {
            login_command,
            wellcome_command
        };
        for (int i = 0; i < sizeof (cmd_list) / sizeof (cmd_list[0]); ++i) {
            w_client.fire(cmd_list[i]);
            agent *a = w_client.extract(cmd_list[i]);
            if (NULL == a) {
                std::cout << "extract failed : " << cmd_list[i] << std::endl;
                continue;
            }
            a->set("name", ".{1-8}");
            a->valid();
        }
        std::cout << "-----------------" << version << " end -------------" << std::endl;
    }

    void test() {
        std::cout << "new test begin" << std::endl;

        test_client<bblc_version>();
     //   test_client<nets_version>();

    }
}
using namespace std;

static const std::string UIlogin = "loginView";
static const std::string NTlogin = "wallet/login";

template <const std::string &testName>
struct SkillTest {

    marshal::agent *operator()(const std::string &command, marshal::agent &wi) {
        if (command != testName) {
            std::cout << "Skill[" << testName << "] no process " << command << std::endl;
            return NULL;
        }

        std::cout << testName << " = {" << std::endl;
        wi.for_each(NULL,
                [](void *c, const std::string &k, const std::string & v) {
                    std::cout << k << " = " << v << std::endl; });

        std::cout << "};" << std::endl;
        if (command == UIlogin) {
            wi.valid();
            wi.finished();
        } else if (command == NTlogin) {
            // wi->valid(NULL,NULL);
            // wi->finished();
        }

        return &wi;
    }
};
#endif
