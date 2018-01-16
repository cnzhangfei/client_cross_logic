/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   information.h
 * Author: ShiHua
 *
 * Created on 2017年9月13日, 下午3:26
 */

#ifndef INFORMATION_H
#define INFORMATION_H

#include "commands.hpp"
#include "item_def.hpp"
#include "action_details.hpp"
#include "http_request.hpp"

namespace marshal {

    template<int commandId, int commandType, int Version>
    struct information {

        enum {
            id = commandId, type = commandType
        };

        constexpr static const char* name() {
            return "";
        }

        template<class T, class D>
        static void invoke(const T& req, D&) {
            std::cout << req << std::endl;
        }
    };

    static const std::string HTTP_HOST = "127.0.0.1";
    static const std::string HTTP_POST = "POST";
#define Http_Information(_id,_name) static const std::string _id##__http_url = _name;\
template<int Version>\
struct information<_id,http_command,Version>{\
    enum{id = _id,type = http_command};\
    constexpr static const char* name(){return _name;}\
    template<class T,class D>\
    static void invoke(const T& req, D& rsp){\
        http_entity<HTTP_HOST,Version>::template invoke<HTTP_POST,_id##__http_url,T,D>(req,rsp);\
    }\
};

    enum em_as {
        aa = 1
    };

    Http_Information(aa, "aa")

#define Gui_Information(_id,_name) template<int Version>\
struct information<_id,gui_command,Version>{\
    enum{id = _id,type = gui_command};\
    constexpr static const char* name(){return _name;}\
};

#define Action_Information(_id,...) template<int Version>\
struct information<_id,action_command,Version> : public action_details<_id,Version,__VA_ARGS__>{\
    enum{id = _id,type = action_command};\
    constexpr static const char* name() { return #_id;}\
};

    template<int Version>
    struct information<-1, action_command, Version> : public action_details<-1, Version, -1 > {

        constexpr static const char* name() {
            return "unknow command";
        }
    };


#define Action_BEG(_name) 

#define Action_DEF(_id,_viewName,_httpUrl,...) Action_Information(_id,__VA_ARGS__) \
Gui_Information(_id,_viewName)\
Http_Information(_id,_httpUrl)\

#define Action_END(_name) 

#include "../action_list.hpp"
}


#endif /* INFORMATION_H */

