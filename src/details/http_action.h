/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   http_action.h
 * Author: ShiHua
 *
 * Created on 2017年9月14日, 上午11:27
 */

#ifndef HTTP_ACTION_H
#define HTTP_ACTION_H

#include <sstream>
#include <vector>
#include "action_details.h"
#include "http_request.h"
#include "action.h"
#include "debug.h"

namespace marshal {

    template <int Version>
    struct information<http_command, action_command, Version> : public action_details<http_command, Version, -1 > {

        enum {
            id = http_command,
            type = action_command
        };

        static constexpr const char *const name() {
            return "http_command";
        }

        template <class T>
        static void for_each(const T *store, std::function<void(const std::string &, const std::string &) > it) {
            it("开心就好", "开心就好");
        }
    };

    /**
     * 创建HTTP请求特例化动作
     */
    template <class T, int Version>
    class action<T, Version, http_command> {
    private:

        std::string escape(const std::string &src) {
            std::stringstream result;
            std::for_each(src.begin(), src.end(), [&result](const char &c) {
                switch (c) {
                    case '"':
                        result << "\\\"";
                        break;
                    case '\t':
                        result << "\\t";
                        break;
                    case '\n':
                        result << "\\n";
                        break;
                    case '\r':
                        result << "\\r";
                        break;
                    case '\\':
                        result << "\\\\";
                        break;
                    default:
                    {
                        result << c;
                        break;
                    }
                }
            });
            return result.str();
        }

    public:
        typedef action_imp<T, Version> imp_action;
        typedef data_store<imp_action, Version> imp_data_store;

        enum {
            id = http_command
        };

        template <int Source>
        void on(const place_holder<Source> &) {
            typedef information<Source, action_command, Version> action_information;
            typedef information<Source, http_command, Version> http_information;

            debug_msg("will be request %s = url(%s)",
                    action_information::name(),
                    http_information::name()
                    );
            imp_data_store *imp = (imp_data_store *)this;
            std::stringstream ss;
            ss << "{";
            action_information::for_each(
                    imp,
                    [this, &ss](const std::string &k, const std::string & v) {
                        ss << "\"" << k << "\":\"" << this->escape(v) << "\",";
                    });
            ss << "\"id\":\"" << Source << "\"}";

            http_information::template invoke(ss.str(), *imp);
        }
    };
}

#endif /* HTTP_ACTION_H */
