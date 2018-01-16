/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   action_list.h
 * Author: ShiHua
 *
 * Created on 2017年9月13日, 下午3:07
 */



Action_BEG(actions)
Action_DEF(login_command, "loginView","/Login",item_id::em_name, item_id::em_pass, item_id::em_capt)
Action_DEF(wellcome_command,"wellView","/initSession",-1)
Action_END(actions)



#undef Action_BEG
#undef Action_DEF
#undef Action_END


