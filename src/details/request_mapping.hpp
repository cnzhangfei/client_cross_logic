#ifndef REQUEST_MAPPING_H
#define REQUEST_MAPPING_H
#include "http_request.hpp"
#include "url_mapping.hpp"
#include "json.hpp"
#include <regex>
#include <string>

namespace marshal {

    template <int commandId, int Version>
    class request_mapping {
    private:
        typedef typename url_mapping<commandId, Version>::request http_request;
        typedef typename url_mapping<commandId, Version>::response http_response;

    public:
        template <class T>
        static std::string aggregate(const T*const store){
            return store->template aggregate<http_request>();
        }
        template <class T>
        static void leach(const std::string& src,T* store){
            store->template leach<http_response>(src);
        }
    };
}

#endif
