/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   action.h
 * Author: ShiHua
 *
 * Created on 2017年9月13日, 下午3:06
 */

#ifndef ACTION_H
#define ACTION_H

#include "information.h"
#include "commands.h"
#include "debug.h"

namespace marshal {

    template<int V>
    struct place_holder {

        enum {
            value = V
        };

    };

    template<class T, int Version>
    class action_imp;

    template<class T, int Version, int CommandId>
    class action {
    public:
        typedef action_imp<T, Version> imp_action;

        enum {
            id = CommandId
        };

        template<int Source>
        void on(const place_holder<Source>&) {
            imp_action* imp = (imp_action*)this;
            imp->fire(place_holder<gui_command>(), place_holder<id>());
        }

    public:

        void valid() {
            imp_action* imp = (imp_action*)this;
            debug_msg("will be excute http_command = %d",id);
            imp->fire(place_holder<http_command>(), place_holder<id>());
        }
    };

}

#endif /* ACTION_H */

