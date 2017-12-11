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
#define debug_msg(fmt,...)  do{\
    char __buffer__[1024] = {0};\
    snprintf(__buffer__,sizeof(__buffer__) -1 ,"[%s-%d]:" fmt,__FILE__,__LINE__, ##__VA_ARGS__);\
    std::cout <<  __buffer__  << std::endl;\
}while(0)

#define error_msg debug_msg
#define hint_msg  debug_msg
}

#endif /* DEBUG_H */

