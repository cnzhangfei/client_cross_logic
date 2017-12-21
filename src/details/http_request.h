#ifndef __HTTP_REQUEST__
#define __HTTP_REQUEST__
#include <unordered_map>
#include <vector>
#include <boost/asio.hpp>

namespace marshal
{

class http_item
{
  protected:
    typedef std::unordered_map<std::string, std::string> http_headers;
    http_headers headers;
    boost::asio::const_buffer contents;

  public:
};

template <const std::string &Host, const std::string &method, const std::string &url, int Version>
class http_request : public http_item
{
  private:
    typedef std::unordered_map<std::string, std::string> http_headers;
    http_headers headers;
    boost::asio::const_buffer contents;

  public:
    template <class T>
    http_request(const T &content) : contents(boost::asio::buffer(content))
    {
        headers["Host"] = Host;
        headers["Accept"] = "application/json";
        headers["Connection"] = "Keep-Alive";
        headers["Content-Length"] = boost::asio::buffer_size(contents);
    }

  public:
    /**
         * 这里是一个坑，和常用的方法不一样
         * 把自己输送到输出流
         * @param ios
         * @return 
         */
    http_request &operator>>(std::ostream &ios)
    {
        ios << method << " " << url << " HTTP/1.1\r\n";
        std::for_each(headers.begin(), headers.end(), [&ios](http_headers::const_reference r) {
            ios << r.first << " : " << r.second << "\r\n";
        });
        ios << "\r\n";
        ios << contents;
        //ios.write(contents.data(), contents.size());
        return *this;
    }
};

template <const std::string &Host, const std::string &url, const std::string &method, int Version>
class http_response : public http_item
{
  public:
    /**
         * 这里一样是一个坑，从输入流中还原自己
         * @param ios
         * @return 
         */
    http_response &operator<<(std::istream &is)
    {
    }

    template <class T>
    http_response &operator>>(T &rsp)
    {
    }
};

template <const std::string &Host, int Version>
struct http_entity
{

    template <const std::string &method, const std::string &url, class T, class D>
    static void invoke(const T &req, D &rsp)
    {
        typedef boost::asio::ip::tcp::iostream http_iostream;
        static http_iostream stream;
        if (!stream)
        {
            stream.connect(Host, "http");
        }
        http_request<Host, method, url, Version> req_message(req);
        http_response<Host, method, url, Version> rsp_message;
        req_message >> stream;
        rsp_message << stream >> rsp;
    }
};
}
#endif