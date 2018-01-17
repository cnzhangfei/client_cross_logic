/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   debug.h
 * Author: ShiHua
 *
 * Created on 2017年9月14日, 下午2:41
 */

#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#include <string.h>
namespace marshal {

#ifndef debug_msg
#define debug_msg(fmt,...)  do{\
    char __buffer__[1024] = {0};\
    snprintf(__buffer__,sizeof(__buffer__) -1 ,"debug[%s-%d-%s]:" fmt,\
    __FILE__,\
    __LINE__,\
    __FUNCTION__,\
    ##__VA_ARGS__);\
    std::cout <<  __buffer__  << std::endl;\
}while(0)
#endif

#ifndef error_msg
#define error_msg debug_msg
#endif

#ifndef warn_msg
#define warn_msg debug_msg
#endif

#ifndef hint_msg
#define hint_msg  debug_msg
#endif

}

#endif /* DEBUG_H */

