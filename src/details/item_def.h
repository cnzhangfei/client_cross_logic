/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   item_def.h
 * Author: ShiHua
 *
 * Created on 2017年9月12日, 下午5:02
 */

#ifndef ITEM_DEF_H
#define ITEM_DEF_H


namespace marshal {





#define Action_Item_BEG(_name) namespace item_id { \
    enum _name {
#define Action_Item_DEF(_name,...) em_##_name,
#define Action_Item_END(_name) }; \
    }
#include "../item_list.h"





    template<int id, int Version>
    struct item_details;


#define Action_Item_BEG(_name)  
#define Action_Item_DEF(_name,_regex,...) template<int Version>\
    struct item_details<item_id::em_##_name,Version>{\
        enum { id = item_id::em_##_name };\
        static const char*const name(){\
                return #_name;\
        }\
        static bool name(const std::string& k) {\
            return k == #_name;\
        }\
        static bool value(const std::string& val) {\
            return val == #_regex;\
        }\
        static const char*const es(int i){\
            static const char* const result[] = {\
                __VA_ARGS__ \
            };\
            i = (i < sizeof(result) / sizeof(result[0])) ? i : 0;\
            return result[i];\
        }\
    };
#define Action_Item_END(_name) 
#include "../item_list.h"
}




#endif /* ITEM_DEF_H */

