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
#include "action.h"
#include "action_details.h"
#include <boost/asio.hpp>

namespace marshal {

    template<int Version>
    struct information<http_command, action_command, Version> :
    public action_details<http_command, Version,-1> {

        enum {
            id = http_command, type = action_command
        };
        static constexpr const char*const name(){
            return "http_command";
        }
    };

    template<class T, int Version>
    class action<T, Version, http_command> {
    public:
        typedef action_imp<T, Version> imp_action;

        enum {
            id = http_command
        };

        template<int Source>
        void on(const place_holder<Source>&) {
            const char*const url = information<Source, http_command, Version>::name();
            debug_msg("will be request http --> %s" ,url );
        }
    };
}


#endif /* HTTP_ACTION_H */

