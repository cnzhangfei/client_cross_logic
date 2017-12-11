/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   concrete.h
 * Author: ShiHua
 *
 * Created on 2017年9月13日, 下午3:01
 */

#ifndef CONCRETE_H
#define CONCRETE_H
#include <sstream>

#include "action_details.h"
#include "information.h"
namespace marshal {
    static const std::string no_value("");

    template<class Action, int Version>
    class concrete : public agent {
        template<class FunctionSign, int MethodID>
        class excute;
        typedef information<Action::id, action_command, Version> action_check;
        typedef data_store<typename Action::imp_action, Version> imp_data_store;
    private:
        Action* instance;
    private:

        enum {
            method_valid = 0,
            method_finished,
            method_set,
            method_get,
            method_remove,
            method_forEach,
            method_debug,
            method_clone
        };

        template<class FunctionSign>
        struct excute<FunctionSign, method_valid > {

            template <class U, U> struct type_check {
            };

            template <class _1> static void do_it(Action* inst, type_check<FunctionSign, &_1::valid > *) {
                inst->valid();
            }

            template <class > static void do_it(Action* inst, ...) {
                imp_data_store* imp = (imp_data_store*) inst;
                const char* result = action_check::valid(imp);
                if (NULL == result) {
                    return;
                }
                imp->set("error_code", "-1");
                imp->set("error_rsp", result);
            }
        };

        template<class FunctionSign>
        struct excute<FunctionSign, method_finished> {

            template <class U, U> struct type_check {
            };

            template <class _1> static void do_it(Action* inst, type_check<FunctionSign, &_1::finished > *) {
                inst->finished();
            }

            template <class > static void do_it(Action* inst, ...) {
                ;
            }
        };

        template<class FunctionSign>
        struct excute<FunctionSign, method_set> {

            template <class U, U> struct type_check {
            };

            template <class _1> static bool do_it(Action* inst, const std::string& k, const std::string& v, type_check<FunctionSign, &_1::set > *) {
                return inst->set(k, v);
            }

            template <class > static bool do_it(Action* inst, const std::string& key, const std::string& val, ...) {
                imp_data_store* imp = (imp_data_store*) inst;
                const char* result = action_check::check(key, val);
                if (NULL == result) {
                    imp->set(key, val);
                    return true;
                }
                imp->set("error_code", "-1");
                imp->set("error_rsp", result);
                return false;
            }
        };

        template<class FunctionSign>
        struct excute<FunctionSign, method_get> {

            template <class U, U> struct type_check {
            };

            template <class _1> static const std::string& do_it(Action* inst, const std::string& k, type_check<FunctionSign, &_1::get > *) {
                return inst->get(k);
            }

            template <class > static const std::string& do_it(Action* inst, const std::string& key, ...) {
                const char* result = action_check::check(key);
                imp_data_store* imp = (imp_data_store*) inst;
                if (NULL == result) {
                    return imp->get(key);
                }
                imp->set("error_code", "-1");
                imp->set("error_rsp", result);
                return no_value;
            }
        };

        template<class FunctionSign>
        struct excute<FunctionSign, method_remove> {

            template <class U, U> struct type_check {
            };

            template <class _1> static const std::string do_it(Action* inst, const std::string& k, type_check<FunctionSign, &_1::remove > *) {
                return inst->remove(k);
            }

            template <class > static const std::string do_it(Action* inst, const std::string& key, ...) {
                const char* result = action_check::check(key);
                imp_data_store* imp = (imp_data_store*) inst;
                if (NULL == result) {
                    return imp->remove(key);
                }
                imp->set("error_code", "-1");
                imp->set("error_rsp", result);
                return no_value;
            }
        };

    public:

        static agent* make_agent(Action* imp) {
            static agent* concrete_agent = NULL;
            if (NULL != concrete_agent) {
                return concrete_agent;
            }
            hint_msg("will be create conreate : %s",action_check::name());
            return concrete_agent = new concrete<Action, Version>(imp);
        }
    protected:

        concrete(Action* imp) {
            instance = (Action*) imp;
        }
    public:

        bool set(const std::string& key, const std::string& val) {
            typedef excute<bool(Action::*)(const std::string&, const std::string&), method_set> set_method;
            return set_method::template do_it<Action>(instance, key, val, 0);
        }

        std::string remove(const std::string& key) {
            typedef excute<const std::string(Action::*)(const std::string&, const std::string&), method_remove> remove_method;
            return remove_method::template do_it<Action>(instance, key, 0);
        }

        const std::string& get(const std::string& key) const {
            typedef excute<const std::string & (Action::*)(const std::string&, const std::string&), method_get> get_method;
            return get_method::template do_it<Action>(instance, key, 0);
        }

        void valid() {
            typedef excute<void(Action::*)(), method_valid> valid_method;
            valid_method::template do_it<Action>(instance, 0);
        }

        void finished() {
            typedef excute<void(Action::*)(), method_finished > finished_method;
            finished_method::template do_it<Action>(instance, 0);
        }

        void for_each(void* context, Consume consumer) const {
            action_check::for_each(
                    (imp_data_store*) instance,
                    [context, consumer](const std::string& k, const std::string & v) {
                        if (consumer) {
                            consumer(context, k, v);
                        }
                    });
        }

        void debug(const std::string& name) const {
            std::stringstream ss;
            for_each(NULL, [&ss](void*, const std::string&k, const std::string & v) {
                ss << k << " : " << v << "," << std::endl;
            });
            std::string result = ss.str();
            hint_msg("%s = {\n %s \n};//%s",name.c_str(),result.c_str(),name.c_str());
        }

        agent* clone() const {
            return NULL;
        }
    };
}

#endif /* CONCRETE_H */

