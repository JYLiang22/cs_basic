- [tcp\_tw\_recycle](#tcp_tw_recycle)
- [半连接队列满了](#半连接队列满了)
- [全连接队列满了](#全连接队列满了)


# tcp_tw_recycle
1. 首先从四次挥手出发，介绍TIME_WAIT是会占用端口资源的，如果客户端（发起连接方）的 TIME_WAIT 状态过多，占满了所有端口资源，那么就无法对**目的 IP+ 目的 PORT**都一样的服务器发起连接了，但是被使用的端口，还是可以继续对另外一个服务器发起连接的。
2. TIME_WAIT 状态的作用
   1. 防止具有相同四元组的旧数据包被收到，也就是防止历史连接中的数据，被后面的连接接受，否则就会导致后面的连接收到一个无效的数据
   2. 保证被动关闭连接的一方能被正确的关闭，即保证最后的 ACK 能让被动关闭方接收，从而帮助其正常关闭
3. 为了避免端口占用问题，提供了两个系统参数来快速回收处于 TIME_WAIT 状态的连接
   1. net.ipv4.tcp_tw_reuse：该选项只适用于连接发起方，作用在调用 connect() 函数时
   2. net.ipv4.tcp_tw_recycle
   3. 使得这两个选项生效，有一个前提条件，就是要打开 TCP 时间戳，即 net.ipv4.tcp_timestamps=1(默认即为 1)。
4. tcp_timestamps 选项开启之后， PAWS 机制会自动开启，它的作用是防止 TCP 包中的序列号发生绕回
5. 开启了 recycle 和 timestamps 选项，就会开启一种叫 per-host 的 PAWS 机制。per-host 是对「对端 IP 做 PAWS 检查」，而非对「IP + 端口」四元组做 PAWS 检查
6. 接下去的看得还是有点懵，多看几遍吧


# 半连接队列满了
当服务器收到syn攻击，就可能导致tcp半连接队列满，这时后面的syn包都会被丢弃。<br>
防御SYN攻击的方法：
1. 增大半连接队列 
2. 可以通过开启syncookies功能，这个有点像tcp fast open里面的cookie
3. 减少 SYN+ACK 重传次数


# 全连接队列满了
1. 调大 accpet 队列的最大长度，调大的方式是通过调大 backlog 以及 somaxconn 参数
2. 检查系统或者代码为什么调用 accept() 不及时