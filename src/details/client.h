/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   client.h
 * Author: ShiHua
 *
 * Created on 2017年9月13日, 下午3:08
 */

#ifndef CLIENT_H
#define CLIENT_H
#include "commands.h"
#include "data_store.h"
#include "action.h"
#include "agent.h"
#include "concrete.h"
#include "http_action.h"
#include "gui_action.h"

namespace marshal {

    template<int Version, typename...Actions>
    class w_client : public Actions... {
    };

    template<class T, int Version>
    class action_imp {
    public:

        template<int Dst, int Src>
        void fire(const place_holder<Dst>&, const place_holder<Src>&) {
            typedef action<T, Version, place_holder<Dst>::value> imp_action;
            imp_action* imp = (imp_action*)this;
            imp->on(place_holder<Src>());
        }

        template<int Holder>
        agent* extract(const place_holder<Holder>&) {
            typedef action<T, Version, place_holder<Holder>::value> imp_action;
            return concrete<imp_action, Version>::make_agent((imp_action*)this);
        }
    };

#define Action_BEG(actions)
#define Action_DEF(_cmd,...) public action<w_client<Version>,Version,_cmd>,
#define Action_END(actions)

    template<int Version>
    class w_client<Version> :
    public data_store<w_client<Version>, Version>,
    public action_imp<w_client<Version>, Version>,
#include "../action_list.h"
    public action<w_client<Version>, Version, http_command>,
    public action<w_client<Version>, Version, gui_command> {
    };

}


#endif /* CLIENT_H */

