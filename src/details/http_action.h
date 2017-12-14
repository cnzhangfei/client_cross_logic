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
#include <boost/asio.hpp>

namespace marshal {

class http_excuter {
public:
	std::string get_remote_data(const std::string& url,
			const std::string& data) {
		stream << "GET " << url << " HTTP/1.0\r\n";
		stream << "Host: " << host << " \r\n";
		stream << "Accept: */* \r\n";
		stream << "Connection: Keep-Alive \r\n";
		stream << "\r\n";
	}

public:
	http_excuter() {
		reconnet();
	}
	~http_excuter() {
	}
protected:
	void reconnet() {
		if (!stream) {
			stream.connect("172.17.21.22", 8000);
			if (!stream) {
				debug << "connect to remote failed" << std::endl;
				return;
			}
		}
	}
protected:
	boost::asio::ip::tcp::iostream stream;
};

template<int Version>
struct information<http_command, action_command, Version> : public action_details<
		http_command, Version, -1> {

	enum {
		id = http_command, type = action_command
	};

	static constexpr const char* const name() {
		return "http_command";
	}

	static std::string request() {
		std::stringstream ss;
		return ss.str();
	}
};

template<class T, int Version> class action<T, Version, http_command> {
public:
	typedef action_imp<T, Version> imp_action;

	enum {
		id = http_command
	};

	template<int Source> void on(const place_holder<Source>&) {
		const char* const url =
				information<Source, http_command, Version>::name();
		// const std::string data = information<Source, http_command, Version>::request();
		http_excuter he;

		debug_msg("will be request http --> %s", url);
	}

protected:
	std::unordered_map<std::string, std::string> remote_data;

protected:
	std::string invoke(const std::string& url, const std::string& data) {
	}
};
}

#endif /* HTTP_ACTION_H */
