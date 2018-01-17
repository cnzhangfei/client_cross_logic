
#ifndef URL_MAPPING_H
#define URL_MAPPING_H

#include "information.hpp"

namespace marshal {

    template <int command_type, int Version>
    struct url_mapping {
        typedef action_details<command_type, Version, -1 > request;
        typedef action_details<command_type, Version, -1 > response;
    };

    template <int Version>
    struct url_mapping<login_command, Version> {
        typedef action_details<login_command, Version, item_id::em_name, item_id::em_pass, item_id::em_capt, -1 > request;
        typedef action_details<login_command, Version, item_id::em_name, -1 > response;
    };
}

#endif