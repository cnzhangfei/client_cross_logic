#include <jni.h>
#include <android/log.h>
#include <string>
#include <functional>
#define  BOOST_ERROR_CODE_HEADER_ONLY 1

#define  debug_msg(...) do{\
    char buffer[1024] = {0};\
    snprintf(buffer,sizeof(buffer),__VA_ARGS__);\
    __android_log_print(ANDROID_LOG_DEBUG,"JNI_BASE","[%s:%d:%s]%s",__FILE__,__LINE__,__FUNCTION__,buffer);\
}while(0)

#include "special_client.h"




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
            debug_msg("nets will be excute gui --> %s",view_name);
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
            debug_msg("bblc will be excue gui -->%s",view_name);
        }
    };
}

namespace marshal {

    template <int version>
    void test_client() {
       debug_msg("-----------------%d begin----------------------",version);
        w_client_pub<version> w_client;
        int cmd_list[] = {
                login_command,
                wellcome_command
        };
        for (int i = 0; i < sizeof (cmd_list) / sizeof (cmd_list[0]); ++i) {
            w_client.fire(cmd_list[i]);
            agent *a = w_client.extract(cmd_list[i]);
            if (NULL == a) {
                debug_msg("exract failed : %d" , cmd_list[i]);
                continue;
            }
            a->set("name", ".{1-8}");
            a->valid();
        }
        debug_msg("----------------%d end-----------------------",version);
    }

    void test() {
        debug_msg("new test begin");
        test_client<bblc_version>();
        test_client<nets_version>();

    }
}


extern "C"
JNIEXPORT jstring

JNICALL
Java_com_feizhang_test_baseapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    marshal::test();
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
