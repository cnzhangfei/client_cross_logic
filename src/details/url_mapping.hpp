
#ifndef URL_MAPPING_H
#define URL_MAPPING_H

#include "information.hpp"

namespace marshal{
    typedef action_details<login_command,item_id::em_name, item_id::em_pass, item_id::em_capt> login_request;
    typedef action_details<login_command,item_id::em_name,item_id::nike_name> login_response;
}

#endif