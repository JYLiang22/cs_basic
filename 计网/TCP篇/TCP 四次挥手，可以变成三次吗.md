- [TCP 四次挥手](#tcp-四次挥手)
  - [为什么 TCP 挥手需要四次呢](#为什么-tcp-挥手需要四次呢)
  - [粗暴关闭 vs 优雅关闭](#粗暴关闭-vs-优雅关闭)
- [什么情况会出现三次挥手](#什么情况会出现三次挥手)


# TCP 四次挥手
再一次介绍四次挥手的过程


## 为什么 TCP 挥手需要四次呢
主要是因为服务端可能有数据还没发送完，所以一般会使用四次挥手。


## 粗暴关闭 vs 优雅关闭
再次结合四次挥手的过程，详细介绍close和shutdown两个函数，它们在关闭、多进程/线程下的区别。


# 什么情况会出现三次挥手
1. 没有数据要发送并且开启了 TCP 延迟确认机制，那么第二和第三次挥手就会合并传输，这样就出现了三次挥手
2. TCP 延迟确认机制：前面讲过的糊涂窗口综合征的解决策略
