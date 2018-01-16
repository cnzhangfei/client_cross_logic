/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   item_list.h
 * Author: ShiHua
 *
 * Created on 2017年9月12日, 下午5:03
 */




Action_Item_BEG(items)
Action_Item_DEF(name, ".{1,8}", "用户名错误", "name error")
Action_Item_DEF(pass, ".{1,8}", "密码错误", "pass error")
Action_Item_DEF(capt, ".{1,8}", "")
Action_Item_DEF(nike_name,".{1,8}","","")
Action_Item_END(items)

#undef Action_Item_BEG
#undef Action_Item_DEF
#undef Action_Item_END

