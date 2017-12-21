# 本工程试图创建一个操作系统无关的、UI无关的应用逻辑Framework

MVC，MVVC等框架虽然从很大程度上解决了视图、数据和控制之间的耦合问题。但是在使用和理解上面还是颇有一些门槛，本工程视图从MS最早的document-view模型出发，构建一个简单，可测试的开发Framework。

## 问题范围

本工程视图解决C/S架构下的APP开发UI层和逻辑混合的问题

## 出发点

iOS下面基本是Obj-c和swift，安卓下面基本是Java。为了减少不必要的理解门槛，本工程采用c++进行开发，使用对应平台的adapter进行UI调用，使用JSON字符串进行数据交换。

## 一些约定

1. 尽可能采用header only的方式提供逻辑库，但是像OPENSSL等第三方依赖库可能需要妥协

2. 尽可能多的使用推导，能在编译期做的检测不推迟到运行期进行检查

