# 目录  
[案例引入](#标题1)
[C++正则表达式库介绍](#标题1)  
[各种常用符号的解释](#标题1) 
- [](#标题1-1)
- [](#标题1-1)


<a name="标题1"></a>
# 案例引入
当我们去网站注册账号，需要设置密码时，可能会出现以下限制：<br>![案例引入](%E6%A1%88%E4%BE%8B%E5%BC%95%E5%85%A5.png)<br>
总体来说，就是如下两个限制规则：
1. 长度为6-16位
2. 密码中必须包含数字、大写字母、小写字母、特殊字符(指定字符中选择)
如果我们没有学过正则表达式，那么写这个检验密码的代码将会十分麻烦：只能通过遍历这个输入的密码中的每个字符，实现多个if语句进行判断。


<a name="标题1"></a>
# C++正则表达式库介绍
C++正则表达式库(RE库)定义在头文件<regex>中，常用的几个RE库组件如下：<br>
| RE库名称 | 解释 |
| -- | -- |
| regex | 表示有一个正则表达式的类 |
| regex_match | 将一个字符序列与一个正则表达式匹配 |
| regex_search | 寻找第一个与正则表达式匹配的子序列 |
| regex_replace | 使用给定格式替换一个正则表达式 | 
| sregex_iterator | 迭代器适配器，调用regex_search来遍历一个string中所有匹配的子串 |
| smatch | 容器类，保存string中搜索的结果 |
| ssub_match | string中匹配的子表达式的结果 |


<a name="标题1"></a>
# 各种常用符号的解释
^ $
```
^：限定开头的字符
$：限定结尾的字符
```
<br>
\d \D \s \S \w \W
```
\d：匹配数字字符
\D：匹配非数字字符
\s：匹配空格
\S：匹配非空格
\w：匹配一般字符（字母，数字，下划线）
\W：匹配除了字母/数字、下划线外的字符
```
<br>
.
```
. ：匹配任意单个字符
```
<br>
|
```
| (竖线) 则表示或的关系，表示检测的字符串须满足其中一个时，才符合条件
```
<br>
```
[^ ] 表示不与中括号里的任意字符匹配
a[^bcd]e：则表示a和e的中间除b，c，d这三个字符外，其他的字符都满足
```
<br>
* + ? {…}
```
*：*前的单个字符可以出现任意次（单个字符包括空格）
+：+前的单个字符至少出现一次（单个字符不包括空格）
?：?前的单个字符最多出现一次
{n}：这里的 n 是一个非负整数。匹配确定的前面的子表达式 n 次
{n,m}：m和n均为非负整数，其中 n<=m。最少匹配 n 次且最多匹配 m 次
```
<br>
() {} []
```
()分组:(123)，这样可以将匹配到的123取出来
{}长度:{4,9}，这个表示前一个字符串的长度为4到9
[]范围:[a-z]，这个表示匹配所有的小写字母
```
<br>
\num
```
这里的num指number，也就是数字，当\后面跟数字，表示匹配第几个括号中的结果
ab(c)d\1：等同于 abcdc
ab(c)(d)\1\2：等同于 abcdcd，也等同于 ab(cd)\1
```


先了解到这里，具体要用到的时候可以参考这两个[blog1](https://blog.csdn.net/weixin_43229348/article/details/124656388?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169595553716800222890854%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=169595553716800222890854&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-4-124656388-null-null.142^v94^chatsearchT3_1&utm_term=C%2B%2B%E4%B8%AD%E7%9A%84%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F&spm=1018.2226.3001.4187)、[blog2](https://blog.csdn.net/qq_43982833/article/details/112498449?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169595553716800222890854%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=169595553716800222890854&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-8-112498449-null-null.142^v94^chatsearchT3_1&utm_term=C%2B%2B%E4%B8%AD%E7%9A%84%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F&spm=1018.2226.3001.4187)以及cpp primer，因为目前自己学这个的目的是要用python的log日志画图，所以先用起来再说。
