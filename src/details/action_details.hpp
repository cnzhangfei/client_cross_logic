/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   check_informations.h
 * Author: ShiHua
 *
 * Created on 2017年9月12日, 下午2:47
 */

#ifndef CHECK_INFORMATIONS_H
#define CHECK_INFORMATIONS_H
#include <functional>
#include "debug.hpp"
#include "item_def.hpp"
namespace marshal {

    static int lang = 0;
    template<int id, int Version>
    struct item_details;


    template <int commandId, int Version, int first, int...Args>
    struct action_details {
        typedef item_details<first, Version> First;

        static const char*const check(const std::string& key) {

            bool result = First::name(key);
            return result ? NULL : action_details<commandId, Version, Args...>::check(key);
        }

        static const char*const check(const std::string& key, const std::string& val) {

            bool result = First::name(val);
            if (!result) {
                return action_details<commandId, Version, Args...>::check(key, val);
            }
            return First::value(val) ? NULL : First::es(lang);
        }

        template<class T>
        static const char*const valid(const T* store) {
            const std::string& key = First::name();
            const std::string& value = store->get(key);
            const char* result = check(key, value);
            if (NULL == result) {
                result = action_details<commandId, Version, Args...>::valid(store);
            }
            return result;
        }

        static void for_each(std::function<void(const std::string&, const std::string&) > it) {
            const std::string& key = First::name();
            const std::string& value = First::value();
            it(key, value);
            action_details<commandId, Version, Args...>::for_each(it);
        }
    };

    template<int commandId, int Version, int last>
    struct action_details<commandId, Version, last> {
        typedef item_details<last, Version> Last;

        static const char* const check(const std::string& key) {
            return Last::name(key) ? NULL : key.c_str();
        }

        static const char*const check(const std::string& key, const std::string& val) {
            bool result = Last::name(key);
            if (!result) {
                return key.c_str();
            }
            return Last::value(val) ? NULL : Last::es(lang);
        }

        template<class T>
        static const char*const valid(const T* store) {
            const std::string& key = Last::name();
            const std::string& value = store->get(key);
            return check(key, value);
        }

        static void for_each(std::function<void(const std::string&, const std::string&) > it) {
            const std::string& key = Last::name();
            const std::string& value = Last::value();
            it(key, value);
        }
    };

    template<int commandId, int Version>
    struct action_details<commandId, Version, -1 > {

        static const char* const check(const std::string& k) {
            return NULL;
        }

        static const char* const check(const std::string& k, const std::string& v) {
            return NULL;
        }

        template<class T>
        static const char*const valid(const T* datastore) {
            return NULL;
        }

        static void for_each(std::function<void(const std::string&, const std::string&) > it) {
            hint_msg("not found special items for : id = %d in version = %d", commandId, Version);
        }
    };
}

#endif /* CHECK_INFORMATIONS_H */

