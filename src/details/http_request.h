#ifndef __HTTP_REQUEST__
#define __HTTP_REQUEST__
#include <unordered_map>
#include <vector>
#include <boost/asio.hpp>
#include "debug.h"

namespace marshal {
    typedef boost::asio::ip::tcp::iostream http_iostream;
    typedef std::unordered_map<std::string, std::string> http_headers;
    const std::string content_length = "Content-Length";

    /**
     * 定义HTTP头信息
     */
    class http_item {
    protected:
        http_headers headers;

    public:

        http_item &operator<<(http_iostream &stream) {
            std::string line;
            stream >> headers["Procotol"] >> headers["State"] >> headers["Describe"];
            std::getline(stream, line);
            for (std::getline(stream, line); !!stream && line != "\r"; std::getline(stream, line)) {
                debug_msg("get line %s", line.c_str());
                char key[256] = {0}, val[256] = {0};
                line += '\n';
                sscanf(line.c_str(), "%[^:]:%[^\n]", key, val);
                headers[key] = val;
            }
            std::for_each(headers.begin(), headers.end(), [](http_headers::const_reference r) {
                debug_msg("%s->%s", r.first.c_str(), r.second.c_str());
            });
            return *this;
        };
    public:

        template<const std::string& name, class T>
        T& header_cast(T& ret) const {
            http_headers::const_iterator it = headers.find(name);
            if(it == headers.end()){
                return ret;
            }
            std::stringstream ss(it->second);
            ss >> ret;
            return ret;
        }
    };

    template <const std::string &host, const std::string &method, const std::string &url, int Version>
    class http_request : public http_item {
    private:
        boost::asio::const_buffer contents;

    public:

        template <class T>
        http_request(const T &content) : contents(boost::asio::buffer(content)) {
            headers["Host"] = host;
            headers["Accept"] = "*/*";
            headers["Connection"] = "Keep-Alive";
        }

    public:

        /**
         * 这里是一个坑，和常用的方法不一样
         * 把自己输送到输出流
         * @param ios
         * @return 
         */
        http_request &operator>>(http_iostream &stream) {
            std::stringstream ss;
            ss << method << " " << url << " HTTP/1.1\r\n";
            std::for_each(headers.begin(), headers.end(), [&ss](http_headers::const_reference r) {
                ss << r.first << ": " << r.second << "\r\n";
            });
            ss << "Content-Length:" << boost::asio::buffer_size(contents) << "\r\n";
            ss << "\r\n";
            debug_msg("%s %s [%s]", method.c_str(), url.c_str(), (const char *) contents.data());

            stream << ss.str();
            stream.write((const char *) contents.data(), contents.size());
            return *this;
        }
    };

    template <const std::string &host, const std::string &method, const std::string &url, int Version>
    class http_response : public http_item {
    protected:
        std::vector<char> contents;

    public:

        /**
         * 这里一样是一个坑，从输入流中还原自己
         * @param ios
         * @return 
         */
        http_response &operator<<(http_iostream &stream) {
            if (!stream || !!stream.error()) {
                error_msg("response stream exception %s on %s",
                        stream.error().message().c_str(),
                        host.c_str());
                return *this;
            }
            *(http_item *)this << stream;
            int size = 0;
            contents.resize(header_cast<content_length>(size));
            stream.read(contents.data(), size);
            debug_msg("wait response message for %s %s/%s = %s",
                    method.c_str(),
                    host.c_str(),
                    url.c_str(),
                    (const char*) contents.data()
                    );
            return *this;
        }

        template <class T>
        http_response &operator>>(T &rsp) {
            return *this;
        }
    };

    template <const std::string &host, int Version>
    struct http_entity {
    private:

        static http_iostream &connect() {
            static http_iostream stream(host, "http");
            for (int i = 0; i < 3 && (!stream || !!stream.error()); ++i) {
                error_msg("stream stated failed or closed(%s),reconnected %s,%d",
                        stream.error().message().c_str(),
                        host.c_str(),
                        i);
                stream.close();
                stream.connect(host, "http");
            }
            debug_msg("connected to %s", host.c_str());
            return stream;
        }

    public:

        template <const std::string &method, const std::string &url, class T, class D>
        static void invoke(const T &req, D &rsp) {
            http_iostream &stream = connect();
            debug_msg("will be request %s(%s)", method.c_str(), url.c_str());
            http_request<host, method, url, Version> req_message(req);
            http_response<host, method, url, Version> rsp_message;
            req_message >> stream;
            rsp_message << stream;
            rsp_message >> rsp;
        }
    };
}
#endif