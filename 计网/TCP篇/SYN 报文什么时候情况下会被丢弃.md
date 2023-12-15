- [tcp\_tw\_recycle](#tcp_tw_recycle)
- [半连接队列满了](#半连接队列满了)
- [全连接队列满了](#全连接队列满了)


# tcp_tw_recycle
这个还是看得不太懂！


# 半连接队列满了
当服务器收到syn攻击，就可能导致tcp半连接队列满，这时后面的syn包都会被丢弃。<br>
可以通过开启syncookies功能，这个有点像tcp fast open里面的cookie


# 全连接队列满了