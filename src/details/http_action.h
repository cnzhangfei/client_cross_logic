/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   http_action.h
 * Author: ShiHua
 *
 * Created on 2017年9月14日, 上午11:27
 */

#ifndef HTTP_ACTION_H
#define HTTP_ACTION_H
#include "action.h"
#include "action_details.h"
#include <sstream>
#include <vector>
#include <boost/asio.hpp>

namespace marshal {

    template <int Version>
    struct information<http_command, action_command, Version> : public action_details<http_command, Version, -1 > {

        enum {
            id = http_command, type = action_command
        };

        static constexpr const char* const name() {
            return "http_command";
        }

    };

    /**
     * 创建HTTP请求特例化动作
     */
    template <class T, int Version>
    class action<T, Version, http_command> {
    private:

        std::string escape(const std::string& src) {
            std::stringstream result;
            std::for_each(src.begin(), src.end(), [&result](const char& c) {
                switch (c) {
                    case '"': result << "\\\"";
                        break;
                    case '\t': result << "\\t";
                        break;
                    case '\n': result << "\\n";
                        break;
                    case '\r': result << "\\r";
                        break;
                    case '\\': result << "\\\\";
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
    public:
        typedef action_imp<T, Version> imp_action;

        enum {
            id = http_command
        };

        template <int Source> void on(const place_holder<Source>&) {
            std::stringstream ss;
            ss << "{";
            information<Source, action_command, Version>::for_each(
                    this,
                    [this, &ss](const std::string& k, const std::string & v) {
                        ss << "\"" << k << "\":\"" << this->escape(v) << "\",";
                    });
            ss << "\"id\":\"" << Source << "\"}";
            information<Source, http_command, Version>::invoke(ss.str(), this);
        }
    };
}

#endif /* HTTP_ACTION_H */
