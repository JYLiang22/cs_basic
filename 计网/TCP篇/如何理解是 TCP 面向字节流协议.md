- [如何理解字节流](#如何理解字节流)
- [如何解决粘包](#如何解决粘包)


# 如何理解字节流
1. TCP是面向字节流的协议，udp是面向报文的协议
2. 理解为什么会这样区分：传输时会不会对信息进行划分
3. 划分有什么好处？路由中转缓存、丢失重传


# 如何解决粘包
1. 什么是粘包？
   - 当两个消息的某个部分内容被分到同一个 TCP 报文时，就是我们常说的 TCP 粘包问题，这时接收方不知道消息的边界的话，是无法读出有效的消息
2. 如何解决粘包？  各种方法的原理、优缺点
   1. 固定长度的消息
   2. 特殊字符作为边界
   3. 自定义消息结构