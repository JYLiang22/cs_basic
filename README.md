# CS_Basics


## 介绍

所学计算机基础知识笔记。<br>


# 项目


## TinySTL

👉[TinySTL](https://github.com/JYLiang22/TinySTL)<br>


## WebServer

👉[TinyWebServer](https://github.com/JYLiang22/TinyWebServer)<br>


## ColoLib

👉[ColoLib](https://github.com/JYLiang22/ColoLib)<br>


## MIT6.s081


## MIT6.824


# 基础


## 计算机组成原理


### 计算机组成与设计：硬件/软件接口 **ARM版**

[ch2 指令：计算机的语言](<计算机组成与设计：硬件软件接口 arm版/笔记/ch2 指令：计算机的语言/笔记.md>)<br>


## 操作系统


### 小林coding笔记梳理

[内存管理知识框架梳理](OS/%E5%B0%8F%E6%9E%97coding%E6%80%BB%E7%BB%93/doc/%E5%86%85%E5%AD%98%E7%AE%A1%E7%90%86%E7%9F%A5%E8%AF%86%E6%A1%86%E6%9E%B6%E6%A2%B3%E7%90%86.md)<br>
[进程管理知识框架梳理](OS/%E5%B0%8F%E6%9E%97coding%E6%80%BB%E7%BB%93/doc/%E8%BF%9B%E7%A8%8B%E7%AE%A1%E7%90%86%E7%9F%A5%E8%AF%86%E6%A1%86%E6%9E%B6%E6%A2%B3%E7%90%86.md)<br>
[调度算法知识框架梳理](OS/%E5%B0%8F%E6%9E%97coding%E6%80%BB%E7%BB%93/doc/%E8%B0%83%E5%BA%A6%E7%AE%97%E6%B3%95%E7%9F%A5%E8%AF%86%E6%A1%86%E6%9E%B6%E6%A2%B3%E7%90%86.md)<br>
[文件系统知识框架梳理](OS/%E5%B0%8F%E6%9E%97coding%E6%80%BB%E7%BB%93/doc/%E6%96%87%E4%BB%B6%E7%B3%BB%E7%BB%9F%E7%9F%A5%E8%AF%86%E6%A1%86%E6%9E%B6%E6%A2%B3%E7%90%86.md)<br>
[网络系统知识框架梳理](OS/%E5%B0%8F%E6%9E%97coding%E6%80%BB%E7%BB%93/doc/%E7%BD%91%E7%BB%9C%E7%B3%BB%E7%BB%9F%E7%9F%A5%E8%AF%86%E6%A1%86%E6%9E%B6%E6%A2%B3%E7%90%86.md)<br>


## 计网


### 小林coding笔记梳理

[IP篇梳理](计网/IP篇梳理.md)<br>


## 算法

无论什么岗位(后端、嵌入式、测开)都要开始看算法啦，现在面试的人太多啦，基本上都要笔试！<br>
详见👉[algorithm](https://github.com/JYLiang22/algorithm)<br>


## 设计模式

设计模式可以分为三个大类，创建型模式、结构型模式、行为型模式，其中创建型模式包括5个设计模式、结构型模式包括7个设计模式、行为型模式包括11个设计模式。<br>
除了优先掌握常用的设计模式外，还要熟悉 [UML类图](Design_Pattern/UML%E7%B1%BB%E5%9B%BE/UML%E7%B1%BB%E5%9B%BE.md)（可以自己根据编程的要求作出类图），熟悉软件设计七大法则。<br>
实际上，七大原则的目的只有一个： **降低对象之间的耦合，增加程序的可复用性、可扩展性和可维护性**。<br>
- 开闭原则：对扩展开放，对修改关闭。   
- 里氏替换原则：不要破坏继承体系，子类重写方法功能发生改变，不应该影响父类方法的含义。    
- 依赖倒置原则：要面向接口编程，不要面向实现编程。   
- 单一职责原则：控制类的粒度大小、将对象解耦、提高其内聚性。   
- 接口隔离原则：要为各个类建立它们需要的专用接口。   
- 迪米特法则：一个类应该保持对其它对象最少的了解，降低耦合度。   
- 合成复用原则：尽量先使用组合或者聚合等关联关系来实现，其次才考虑使用继承关系来实现。   

没有包含在其中的设计模式有以下四个：<br>

|名称|中文名|说明|笔记|
|--|--|--|--|
|Simple Factory |简单工厂模式 | 常用 | [笔记](Design_Pattern/%E7%AE%80%E5%8D%95%E5%B7%A5%E5%8E%82%E6%A8%A1%E5%BC%8F/%E7%AE%80%E5%8D%95%E5%B7%A5%E5%8E%82%E6%A8%A1%E5%BC%8F.md) |
|single responsibility |单一职责模式 | 
|The Open-Closed Principle |开放-封闭模式 | 
|Dependence Inversion Principle |依赖倒转模式 | 

创建型模式如下表：
|创建型模式|	中文名	| 说明 | 笔记 |
|--|--|--|--|
|Abstract Factory/Kit|	抽象工厂模式	| 常用 | [笔记](Design_Pattern/%E6%8A%BD%E8%B1%A1%E5%B7%A5%E5%8E%82%E6%A8%A1%E5%BC%8F/%E6%8A%BD%E8%B1%A1%E5%B7%A5%E5%8E%82%E6%A8%A1%E5%BC%8F.md) |
|Builder|	建造者模式	|
|Factory Method/Virutal Contructor|	工厂方法模式	| 常用 | [笔记](Design_Pattern/%E5%B7%A5%E5%8E%82%E6%96%B9%E6%B3%95%E6%A8%A1%E5%BC%8F/%E5%B7%A5%E5%8E%82%E6%96%B9%E6%B3%95%E6%A8%A1%E5%BC%8F.md) |
|Prototype|	原型模式	|
|Singleton|	单例模式  | 常用 | [笔记](Design_Pattern/%E5%8D%95%E4%BE%8B%E6%A8%A1%E5%BC%8F/%E5%8D%95%E4%BE%8B%E6%A8%A1%E5%BC%8F.md) |

结构型模式如下表：
|结构型模式|	中文名	| 说明 | 笔记 |   
|--|--|--|--|
|Adapter/Wrapper|	适配器模式	|
|Bridge/Handle/Body|	桥接模式  |
|Composite|	组合模式	|
|Decorator/Wrapper|	装饰器模式	| 常用 | [笔记](Design_Pattern/%E8%A3%85%E9%A5%B0%E5%99%A8%E6%A8%A1%E5%BC%8F/%E8%A3%85%E9%A5%B0%E5%99%A8%E6%A8%A1%E5%BC%8F.md) |
|Facade|	外观模式	| 常用 | [笔记](Design_Pattern/%E5%A4%96%E8%A7%82%E6%A8%A1%E5%BC%8F/%E5%A4%96%E8%A7%82%E6%A8%A1%E5%BC%8F.md) |
|Flyweight|	享元模式	|
|Proxy/Surrogate|	代理模式  | 常用 | [笔记](Design_Pattern/%E4%BB%A3%E7%90%86%E6%A8%A1%E5%BC%8F/%E4%BB%A3%E7%90%86%E6%A8%A1%E5%BC%8F.md) | 

行为型模式如下表：
|行为型模式 |	中文名 |	说明 |	笔记 |
|--|--|--|--|
|Chain of Responsibility |	职责链模式 | 常用 | [笔记](Design_Pattern/%E8%81%8C%E8%B4%A3%E9%93%BE%E6%A8%A1%E5%BC%8F/%E8%81%8C%E8%B4%A3%E9%93%BE%E6%A8%A1%E5%BC%8F.md) |
|Command/Action/Transaction | 命令模式 | 常用 | [笔记](Design_Pattern/%E5%91%BD%E4%BB%A4%E6%A8%A1%E5%BC%8F/%E5%91%BD%E4%BB%A4%E6%A8%A1%E5%BC%8F.md) |
|Interpreter |	解释器模式 |
|Iterator/Cursor |	迭代器模式 |
|Mediator |	中介者模式 |
|Memento/Token |	备忘录模式 |
|Observer/Dependents/Publish-Subscribe |	观察者模式 | 常用 | [笔记](Design_Pattern/%E8%A7%82%E5%AF%9F%E8%80%85%E6%A8%A1%E5%BC%8F/%E8%A7%82%E5%AF%9F%E8%80%85%E6%A8%A1%E5%BC%8F.md) |
|State/Objects for States |	状态模式 |
|Strategy/Policy |	策略模式 | 常用 | [笔记](Design_Pattern/%E7%AD%96%E7%95%A5%E6%A8%A1%E5%BC%8F/%E7%AD%96%E7%95%A5%E6%A8%A1%E5%BC%8F.md) | 
|Template Method |	模板方法模式 |
|Visitor |	访问者模式 |

可参考以下资料学习：

1. [CSDN专栏](https://blog.csdn.net/sinat_21107433/category_9418696.html)
2. [设计模式](https://refactoringguru.cn/design-patterns)
3. [卡码网设计模式](https://kamacoder.com/designpattern.php)


# 语言 


## C++ Primer第五版

[第二章 变量和基本类型](<C++ Primer/第二章 变量和基本类型.md>)<br>
[第三章 字符串、向量和数组](<C++ Primer/第三章 字符串、向量和数组.md>)<br>
[第四章 表达式](<C++ Primer/第四章 表达式.md>)<br>
[第五章 语句](<C++ Primer/第五章 语句.md>)<br>
[第六章 函数](<C++ Primer/第六章 函数.md>)<br>
[第七章 类](<C++ Primer/第七章 类.md>)<br>
[第八章 IO库](<C++ Primer/第八章 IO库.md>)<br> 
[第九章 顺序容器](<C++ Primer/第九章 顺序容器.md>)<br>
[第十章 泛型算法](<C++ Primer/第十章 泛型算法.md>)<br>
[第十一章 关联容器](<C++ Primer/第十一章 关联容器.md>)<br>
[第十二章 动态内存](<C++ Primer/第十二章 动态内存.md>)<br>
[第十三章 拷贝控制](<C++ Primer/第十三章 拷贝控制.md>)<br>
[第十四章 重载运算与类型转换](<C++ Primer/第十四章 重载运算与类型转换.md>)<br>
[第十五章 面向对象程序设计](<C++ Primer/第十五章 面向对象程序设计.md>)<br>
[第十六章 模板和泛型编程](<C++ Primer/第十六章 模板和泛型编程.md>)<br>

[面经](面经总结/doc/语言.md)<br>


# 工具类


## 正则表达式

可以参考以下学习：

1. [github仓库](https://github.com/any86/any-rule)
2. [图解正则网站](https://regexper.com/)


## markdown/latex


## Linux/shell/vim

值得参考的博客：

1. [shell](https://blog.csdn.net/weixin_42313749/article/details/120524768)，学习这个博客的同时自己动手写了一个简单的git自动push脚本，[详见](gitpush.sh)
2. [shell](https://blog.csdn.net/w918589859/article/details/108752592?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169525906716800192280547%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=169525906716800192280547&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-108752592-null-null.142^v94^chatsearchT3_1&utm_term=shell&spm=1018.2226.3001.4187)
3. [Linux/shell/vim](https://blog.csdn.net/as604049322/article/details/120446586?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169525487416800222827078%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=169525487416800222827078&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-120446586-null-null.142^v94^chatsearchT3_1&utm_term=linux&spm=1018.2226.3001.4187)


## git

参考这个[博客](https://www.liaoxuefeng.com/wiki/896043488029600)学习<br>


## gdb/gcc

1. 看[Linux高并发服务器里的笔记](https://github.com/JYLiang22/TinyWebServer/blob/main/project/Linux%E9%AB%98%E5%B9%B6%E5%8F%91%E6%9C%8D%E5%8A%A1%E5%99%A8%E5%BC%80%E5%8F%91/1%20Linux%E7%B3%BB%E7%BB%9F%E7%BC%96%E7%A8%8B%E5%85%A5%E9%97%A8/%E7%AC%94%E8%AE%B0.md)，了解基本使用方法
2. 结合[Debug Hacks](https://github.com/hiro-9999/book-2/blob/master/Debug%20Hacks%20%E4%B8%AD%E6%96%87%E7%89%88.pdf)和项目，学习多线程调试、内存泄漏等gdb方法


## Makefile/cmake

1. Makefile看[Linux高并发服务器里的笔记](https://github.com/JYLiang22/TinyWebServer/blob/main/project/Linux%E9%AB%98%E5%B9%B6%E5%8F%91%E6%9C%8D%E5%8A%A1%E5%99%A8%E5%BC%80%E5%8F%91/1%20Linux%E7%B3%BB%E7%BB%9F%E7%BC%96%E7%A8%8B%E5%85%A5%E9%97%A8/%E7%AC%94%E8%AE%B0.md)，自己动手写写，不难！
2. 参考[CSDN](https://blog.csdn.net/ZBraveHeart/article/details/123187908?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170988428416800185818949%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170988428416800185818949&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~hot_rank-2-123187908-null-null.142^v99^pc_search_result_base3&utm_term=Makefile&spm=1018.2226.3001.4187)
3. 参考[廖雪峰makefile教程](https://liaoxuefeng.com/books/makefile/introduction/index.html)


# 参考

1. [代码随想录](https://github.com/youngyangyang04/leetcode-master)
2. [卡码网](https://kamacoder.com/)
3. [廖雪峰的官方网站](https://liaoxuefeng.com/index.html)
4. [CSDN专栏](https://blog.csdn.net/sinat_21107433/category_9418696.html)
5. [设计模式](https://refactoringguru.cn/design-patterns)
6. [小林coding](https://xiaolincoding.com/)
7. [CSView计算机招聘知识分享](https://www.csview.cn/)
8. [Interviewguide大厂面试真题](https://top.interviewguide.cn/)
9. [阿秀的学习笔记](https://interviewguide.cn/)
10. ...(其他有遗忘)