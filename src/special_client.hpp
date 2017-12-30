/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   http_informations.h
 * Author: ShiHua
 *
 * Created on 2017年9月12日, 下午2:45
 */

#ifndef SPECIAL_CLIENT_H
#define SPECIAL_CLIENT_H
#include "details/commands.hpp"
#include "details/client.hpp"

namespace marshal {

    template<int Version>
    class w_client_pub : public w_client<Version> {
    private:

        struct action_details {
            virtual void fire() = 0;
            virtual agent* extract() = 0;
        };

        template <class T, int command>
        struct action_details_imp : public action_details {
        private:
            T* instance;
        public:

            void fire() {
                instance->fire(place_holder<command>(), place_holder<-1>());
            };

            agent* extract() {
                return instance->extract(place_holder<command>());
            };

            action_details_imp(T* inst) : instance(inst) {
                hint_msg("regist the command : %d", command);
            }
        };


    private:
        std::map<int, action_details*> actions;

    public:

        w_client_pub() {
            actions[login_command] = new action_details_imp<w_client<Version>, login_command>(this);
            actions[gui_command] = new action_details_imp<w_client<Version>, gui_command>(this);
            actions[http_command] = new action_details_imp<w_client<Version>, http_command>(this);
            actions[wellcome_command] = new action_details_imp<w_client<Version>, wellcome_command>(this);
        }

        void fire(int id) {
            action_details* ad = actions[id];
            if (NULL == ad) {
                hint_msg("not found the fire command : %d", id);
                return;
            }
            ad->fire();
        }

        agent* extract(int id) {
            action_details* ad = actions[id];
            if (NULL != ad) {
                return ad->extract();
            }
            hint_msg("not found the aspect : %d", id);
            return NULL;
        }
    };
}

#endif /* SPECIAL_CLIENT_H */

