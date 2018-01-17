#ifndef REQUEST_MAPPING_H
#define REQUEST_MAPPING_H
#include "http_request.hpp"
#include "url_mapping.hpp"
#include <regex>
#include <string>
namespace marshal {

    template <int commandId, int Version>
    class request_mapping {
    private:

        static std::string escape(const std::string& src) {
            std::stringstream result;
            std::for_each(src.begin(), src.end(), [&result](const char& c) {
                switch (c) {
                    case '"':
                        result << "\\\"";
                        break;
                    case '\t':
                        result << "\\t";
                        break;
                    case '\n':
                        result << "\\n";
                        break;
                    case '\r':
                        result << "\\r";
                        break;
                    case '\\':
                        result << "\\\\";
                        break;
                    default:
                    {
                        result << c;
                        break;
                    }
                }
            });
            return result.str();
        }
        
        static std::string pickout(const std::string& src,const std::string& reg){
            return "";
        }

    private:
        typedef typename url_mapping<commandId, Version>::request http_request;
        typedef typename url_mapping<commandId, Version>::response http_response;

    public:
        template <class T>
        static std::string aggregate(const T*const store){
            std::stringstream ss;
            ss << "{";
            http_request::for_each([store, &ss](const std::string & k,const std::string& reg) {
                const std::string v = store->get(k);
                ss << "\"" << k << "\":\"" << escape(v) << "\",";
            });
            ss << "\"id\":\"" << commandId << "\"}";
            return ss.str();
        }
        template <class T>
        static void leach(const std::string& src,T*const dst){
            http_response::for_each([&src,&dst](const std::string& k, const std::string& reg){
                std::stringstream ss;
                ss << "\"" << k << "\":\"(" << reg << ")\"";
                std::string regs = ss.str();
                std::cout << regs << "  :   " << src << std::endl;
                std::regex regex_value(regs);
                std::smatch what;
                if(std::regex_search(src,what,regex_value)){
                    debug_msg("set %s = %s", k.c_str(), what[1].str().c_str());
                    return;
                }
                debug_msg("get %s(%s) value is null",k.c_str(),regs.c_str());
            });
        }
    };
}

#endif
