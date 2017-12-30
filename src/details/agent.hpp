/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   WalletInformationInterface.h
 * Author: ShiHua
 *
 * Created on 2017年8月7日, 上午11:59
 */

#ifndef WALLETINFORMATIONINTERFACE_H
#define WALLETINFORMATIONINTERFACE_H

#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>

namespace marshal {

class agent {
private:
    agent(const agent&);
    agent& operator=(const agent&);

protected:
    typedef std::function<void(void*, const std::string&, const std::string&)> Consume;
    typedef std::function<void(void*, agent*)> Finished;
    agent(){}
    virtual ~agent() {
    }

public:
    virtual bool set(const std::string&, const std::string&) = 0;
    virtual std::string remove(const std::string&) = 0;
    virtual const std::string& get(const std::string&) const = 0;

public:
    virtual void valid() = 0;
    virtual void finished() = 0;
    virtual void for_each(void* context, Consume consumer) const = 0;
    virtual void debug(const std::string& name) const = 0;
    virtual agent* clone() const = 0;
};
}

#endif /* WALLETINFORMATIONINTERFACE_H */
