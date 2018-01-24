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
#include "action_details.hpp"
#include "http_request.hpp"
#include "action.hpp"
#include "debug.hpp"
#include "url_mapping.hpp"

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

       
        static void for_each(std::function<void(const std::string &, const std::string &) > it) {
            it("开心就好", "开心就好");
        }
    };

    /**
     * 创建HTTP请求特例化动作
     */
    template <class T, int Version>
    class action<T, Version, http_command> {
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
                    http_information::name());
            imp_data_store *imp = (imp_data_store *)this;
            http_information::template invoke(imp);
            /*
            std::stringstream ss;
            ss << "{";
            http_request::for_each(
                imp,
                [this, &ss](const std::string &k, const std::string &v) {
                    ss << "\"" << k << "\":\"" << this->escape(v) << "\",";
                });
            ss << "\"id\":\"" << Source << "\"}";

            http_entity<HTTP_HOST,Version>::invoke()
            http_information::template invoke(ss.str(), *imp);*/
        }
    };
}

#endif /* HTTP_ACTION_H */
