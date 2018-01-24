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
#include "json.hpp"
#include "debug.hpp"

namespace marshal {

    template<class T, int Version>
    class data_store {
        typedef std::function<void(const std::string&, const std::string&) > iterator_function;
    private:
        std::string nop;
        std::map<std::string, std::string> store;
    private:
        using json = nlohmann::json;
        json contents;
    public:
        template <class Information>
        std::string aggregate()const{
            json new_contents({});
            Information::for_each([this,&new_contents](const std::string & k,const std::string& reg) {
                json::const_iterator  it = this->contents.find(k);
                if(it != this->contents.end()){
                    new_contents[k] = *it;
                }else{
                    new_contents[k] = nullptr;
                }
            });
            std::string result = new_contents.dump();
            hint_msg("get the json = %s",result.c_str());
            return result;
        }

        template <class Information>
        void leach(const std::string& js){
            try {
                json new_contents = json::parse(js);
                Information::for_each([this,&new_contents](const std::string & k,const std::string& reg) {
                    this->contents[k] = new_contents[k];
                });
                hint_msg("new content = %s",contents.dump().c_str());
            }catch (std::exception& e){
                this->contents["message"] = e.what();
                error_msg("response error = %s",js.c_str());
            }
        }
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

