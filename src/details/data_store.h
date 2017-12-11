/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   data_store.h
 * Author: ShiHua
 *
 * Created on 2017年9月13日, 下午3:00
 */

#ifndef DATA_STORE_H
#define DATA_STORE_H
#include <map>
#include <string>
#include <iostream>

namespace marshal {

    template<class T, int Version>
    class data_store {
        typedef std::function<void(const std::string&, const std::string&) > iterator_function;
    private:
        std::string nop;
        std::map<std::string, std::string> store;
    public:

        void set(const std::string& k, const std::string& v) {
            store[k] = v;
        }

        const std::string& get(const std::string& k)const {
            std::map<std::string, std::string>::const_iterator it = store.find(k);
            return it == store.end() ? nop : it->second;
        }

        const std::string remove(const std::string& k) {
            std::map<std::string, std::string>::const_iterator it = store.find(k);
            it = (it == store.end()) ? it : store.erase(it);
            return it == store.end() ? nop : it->second;
        }

        std::string to_json()const {
            return nop;
        }
    };

}

#endif /* DATA_STORE_H */

