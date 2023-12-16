- [问题引入](#问题引入)
- [什么是 TIME\_WAIT 状态](#什么是-time_wait-状态)
- [为什么要设计 TIME\_WAIT 状态](#为什么要设计-time_wait-状态)
- [tcp\_tw\_reuse 是什么](#tcp_tw_reuse-是什么)
- [为什么 tcp\_tw\_reuse 默认是关闭的](#为什么-tcp_tw_reuse-默认是关闭的)


# 问题引入
既然打开 net.ipv4.tcp_tw_reuse 参数可以快速复用处于 TIME_WAIT 状态的 TCP 连接，那为什么 Linux 默认是关闭状态呢？<br>
其实这题在变相问如果 TIME_WAIT 状态持续时间过短或者没有，会有什么问题？因为开启 tcp_tw_reuse 参数可以快速复用处于 TIME_WAIT 状态的 TCP 连接时，相当于缩短了 TIME_WAIT 状态的持续时间。<br>
先直接看总结吧，反正就是为什么要设计time_wait这两个原因


# 什么是 TIME_WAIT 状态
TIME_WAIT 是主动关闭方断开连接时的最后一个状态，该状态会持续 **2MSL(Maximum Segment Lifetime)** 时长，之后进入CLOSED 状态。<br>
MSL 指的是 TCP 协议中任何报文在网络上最大的生存时间，任何超过这个时间的数据都将被丢弃。


# 为什么要设计 TIME_WAIT 状态
1. 防止历史连接中的数据，被后面相同四元组的连接错误的接收
2. 保证被动关闭连接的一方，能被正确的关闭


# tcp_tw_reuse 是什么


# 为什么 tcp_tw_reuse 默认是关闭的