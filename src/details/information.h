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

#include "commands.h"
#include "item_def.h"
#include "action_details.h"

namespace marshal {

    template<int commandId, int commandType, int Version>
    struct information {

        enum {
            id = commandId, type = commandType
        };

        constexpr static const char* name() {
            return "";
        }
    };

#define Http_Information(_id,_name) template<int Version>\
struct information<_id,http_command,Version>{\
    enum{id = _id,type = http_command};\
    constexpr static const char* name(){return _name;}\
};

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

    

#define Action_BEG(_name) 
#define Action_DEF(_id,_viewName,_httpUrl,...) Action_Information(_id,__VA_ARGS__) \
Gui_Information(_id,_viewName)\
Http_Information(_id,_httpUrl)
#define Action_END(_name) 

#include "../action_list.h"
}


#endif /* INFORMATION_H */

