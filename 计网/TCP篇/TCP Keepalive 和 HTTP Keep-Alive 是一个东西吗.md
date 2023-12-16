- [结论](#结论)
- [HTTP 的 Keep-Alive](#http-的-keep-alive)
- [TCP 的 Keepalive](#tcp-的-keepalive)


# 结论
事实上，这两个完全是两样不同东西，实现的层面也不同：
1. HTTP 的 Keep-Alive，是由应用层（用户态） 实现的，称为 HTTP 长连接；
2. TCP 的 Keepalive，是由 TCP 层（内核态） 实现的，称为 TCP 保活机制


# HTTP 的 Keep-Alive
1. 介绍了什么是HTTP短连接，这个连接的缺点是什么
2. 基于这个缺点，提出了HTTP长连接，也就是HTTP 的 Keep-Alive
3. 基于长连接，出现的HTTP流水线，会有相应的队头阻塞的问题
4. 为了避免资源浪费出现的 keepalive_timeout


# TCP 的 Keepalive 
TCP 保活机制