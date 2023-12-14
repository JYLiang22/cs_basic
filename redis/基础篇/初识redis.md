# 初识redis
## 初识Nosql
redis是一个键值型数据库，如图所示，它可以以键值对的形式存储数据。  
当我们要存储一个员工的信息时，可以像前三行一样分别保存它的id、name、age的键值对，但是这样保存信息太松散了，因为这是一个员工的信息。所以我们可以用第四行的形式存储，key值是一个独一无二的id值，value值是一个json字符串，里面记录了员工的各种信息。  
![初识redis](https://gitee.com/LIANGJYNO1/cs_basics/raw/master/redis/%E5%9F%BA%E7%A1%80%E7%AF%87/image/%E5%88%9D%E8%AF%86redis.PNG)  
所以可以看出，这种数据库和mysql是和不一样的，它既没有表、也没有约束，是一种非关系型数据库，把它称为Nosql。

## SQL和NoSQL的区别
首先，S代表structured的意思，也就是说SQL是一种结构化的数据，这些数据都是有格式上的要求的。例如下图中的用户信息的存储，就会在表定义时给出数据的约束。  
NoSQL对应的就是数据的结构没有非常严格的约束，例如键值型数据、文档型数据和图格式数据。  
![区别1](https://gitee.com/LIANGJYNO1/cs_basics/raw/master/redis/%E5%9F%BA%E7%A1%80%E7%AF%87/image/%E5%8C%BA%E5%88%AB1.PNG)  

其次，关系型数据库之所以这么叫，是因为数据间往往是有关联的，例如下图中所示的以外键的形式把三个表联系起来；  
![区别2](https://gitee.com/LIANGJYNO1/cs_basics/raw/master/redis/%E5%9F%BA%E7%A1%80%E7%AF%87/image/%E5%8C%BA%E5%88%AB2.1.PNG)

而非关系型数据库数据间是没有关联的，如下图，要维护“张三”的订单与商品“荣耀”和“小米11”的关系，不得不冗余的将这两个商品保存在张三的订单文档中。  
![区别2](https://gitee.com/LIANGJYNO1/cs_basics/raw/master/redis/%E5%9F%BA%E7%A1%80%E7%AF%87/image/%E5%8C%BA%E5%88%AB2.2.PNG)

SQL查询是有固定的语法的：  
```MySQL
select 要查询的字段 from 表名 where 条件;
```
而NoSQL查询的语法形式是不统一的，在每一种数据库里面的查询形式都不一样。  
![区别3](https://gitee.com/LIANGJYNO1/cs_basics/raw/master/redis/%E5%9F%BA%E7%A1%80%E7%AF%87/image/%E5%8C%BA%E5%88%AB3.PNG)

第四个区别在于事务上，SQL是支持事务的，需要满足acid的特性；而NoSQL只能做到基本的一致性。   

所以它们两者的区别可以总结如下图：  
![总区别输入图片说明](https://gitee.com/LIANGJYNO1/cs_basics/raw/master/redis/%E5%9F%BA%E7%A1%80%E7%AF%87/image/%E6%80%BB%E5%8C%BA%E5%88%AB.PNG)
其中垂直的意思指的是关系型数据库在设计的时候可能就没有考虑过分布式的数据以及数据分片的需求，所以它的数据都是存在于本机的，这种情况下，影响性能的就是存储数据的服务器的性能了。   
这里注意区分数据分片和主从复制的区别，数据分片指的是每个服务器存储的都是不一样的数据，这样做可以提升存储数据量；而主从复制指的是服务器间的数据都是一样的，并不可以通过这种手段提高存储的数据量，再者主从复制主要是为了满足读写分离，提高并发度。  
而水平的意思，指的是数据是分布式存储的，满足了数据拆分的需求。


## 安装redis
这部分需要先安装vmware workstation Pro 15，再安装centos7.9，之后才能在虚拟机上安装redis。  
Linux部分内容自己确实忘的差不多了，是时候回去看看老韩的Linux课程把重点的复习复习了：例如如何使用xftp传文件、如何远程登录、常用指令等的知识。  
这部分就看视频吧，没有什么好说的。对于自己来说，存在的问题就是对于常用指令和Linux操作的遗忘，复习回来！

# redis常见命令