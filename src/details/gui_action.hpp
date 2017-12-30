/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gui_action.h
 * Author: ShiHua
 *
 * Created on 2017年9月14日, 上午11:27
 */

#ifndef GUI_ACTION_H
#define GUI_ACTION_H

#include "action.hpp"

namespace marshal {

    template<int Version>
    struct information<gui_command, action_command, Version>
    : public action_details<gui_command, Version,-1> {

        enum {
            id = http_command, type = action_command
        };
        
        static constexpr const char*const name(){
            return "gui_command";
        }
    };

    template<class T, int Version>
    class action<T, Version, gui_command> {
    public:
        typedef action_imp<T, Version> imp_action;

        enum {
            id = gui_command
        };

        template<int Source>
        void on(const place_holder<Source>&) {
            const char*const view_name = information<Source, gui_command, Version>::name();
            debug_msg("will be excute gui --> %s",view_name);
        }
    };

}

#endif /* GUI_ACTION_H */

