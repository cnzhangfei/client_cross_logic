/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   commands.h
 * Author: ShiHua
 *
 * Created on 2017年9月12日, 下午6:32
 */

#ifndef COMMANDS_H
#define COMMANDS_H

namespace marshal {


#define Action_BEG(_name) enum _name{__action_beg, \
    action_command,\
    gui_command,\
    http_command,
#define Action_DEF(_name,...) _name,
#define Action_END(_name) __actions_end};
#include "../action_list.hpp"

}


#endif /* COMMANDS_H */

