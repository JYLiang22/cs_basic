- [IO类](#io类)
  - [IO对象无拷贝或赋值](#io对象无拷贝或赋值)
  - [条件状态](#条件状态)
    - [习题](#习题)
  - [管理输出缓冲](#管理输出缓冲)
    - [刷新输出缓冲区](#刷新输出缓冲区)
    - [关联输入和输出流](#关联输入和输出流)
- [文件输入输出](#文件输入输出)
  - [使用文件流对象](#使用文件流对象)
    - [习题](#习题-1)
- [string流](#string流)
  - [使用istringstream](#使用istringstream)
    - [习题](#习题-2)
  - [使用ostringstream](#使用ostringstream)
    - [习题](#习题-3)


# IO类


## IO对象无拷贝或赋值  
如下代码所示，不可以对IO对象拷贝和赋值：   
```cpp
ofstream out1, out2;
out1 = out2;   // 错误：不能对流对象赋值
ofstream print(ofstream);   // 错误：不能初始化ofstream参数
out2 = print(out2);   // 错误：不能拷贝流对象
```


## 条件状态
重新看了一遍，给我的感觉就是再说利用IO库条件状态进行错误处理。但还是看不懂这部分内容该怎么用，有什么用！

### 习题
1. 编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定流中读取数据，直到遇到文件结束标识符时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其位于有效状态。
```cpp
#include<iostream>
#include<stdexcept>
using namespace std;

istream& f(istream &in){
    int v;
    while(in >> v, !in.eof()){   // 直到遇到文件结束符才停止读取
        if(in.bad()){
            throw runtime_error("iostream error");
        }
        if(in.fail()){
            cerr << "data error, try it again: " << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main(){

    cout << "input some nums, press ctrl+z to end!" << endl;
    f(cin);
    return 0;
}
```


## 管理输出缓冲


### 刷新输出缓冲区
```cpp
cout << "hi!" << endl;   // 输出hi和一个换行，然后刷新缓冲区
cout << "hi!" << flush;   // 输出hi，然后刷新缓冲区，不服加任何额外字符
cout << "hi!" << ends;   // 输出hi和一个空字符，然后刷新缓冲区
```


### 关联输入和输出流
这里没搞懂介绍这个有什么用


# 文件输入输出


## 使用文件流对象
直接做题吧，通过题目理解比较好！  


### 习题
1. 编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。
```cpp
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

int main(){

    ifstream in("data.txt");   // 打开文件
    if(!in){
        cerr << "can not open this file!" << endl;
        return -1;
    }

    string line;
    vector<string> words;
    // while(getline(in, line)){   // 从文件中读取一行
    while(in >> line){   // 从文件中读取一个元素
        words.push_back(line);   // 添加到vector中
    }

    for(vector<string>::const_iterator it = words.begin(); it != words.end(); it++){
        cout << *it << endl;
    }

    in.close();

    return 0;
}
```


# string流


## 使用istringstream
当处理的是行内的单个单词时，可以使用istringstream。


### 习题
1. 编写程序，将来自一个文件中的行保存在一个vector<string>中。然后使用一个istringstream从vector中读取数据元素，每次读取一个单词。
```cpp
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char *argv[]){

    if(argc < 2){
        cerr << "argument fault!\n";
        return -1;
    }

    ifstream in(argv[1]);
    if(!in){
        cerr << "can not open file!\n";
        return -1;
    }

    string line;
    vector<string> words;
    while(getline(in, line)){
        words.push_back(line);
    }

    in.close();

    vector<string>::const_iterator it = words.begin();
    while(it != words.end()){
        istringstream line_str(*it);
        string word;
        while(line_str >> word)
            cout << word << " ";
        cout << endl;
        ++it;
    }

    return 0;
}
```

```shell
eason@eason:~/cpp_primer/chapter8$ ./8.10
argument fault!
eason@eason:~/cpp_primer/chapter8$ ./8.10 data.txt
hello world 
hello world 
hello world 
hello world 
hello world 
hello world 
hello world 
hello world 
hello world 
```


## 使用ostringstream


### 习题
1. 重写本节的电话号码程序，从一个命名文件而非cin文件读取数据。
```cpp
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

string format(const string &s) { return s; }

bool valid(const string &s){
    // 如何验证将在17章介绍，应该指的是用正则表达式解决
    // 现在简单返回true
    return true;
}

int main(int argc, char *argv[]){

    string line,word;   // 分别保存来自输入的一行和单词
    vector<PersonInfo> people;   // 保存来自输入的所有记录
    istringstream record;

    if(argc != 2){
        cerr << "please input file name!\n";
        return -1;
    }

    ifstream in(argv[1]);
    if(!in){
        cerr << "can not open file!\n";
        return -1;
    }

    while(getline(in, line)){
        PersonInfo info;   // 创建一个保存此记录的对象
        record.clear();   // 重复使用字符串流，每次都要调用clear
        record.str(line);   // 将记录绑定到刚读入的行
        record >> info.name;   // 读取名字
        while(record >> word)   // 读取电话号码
            info.phones.push_back(word);
        people.push_back(info);
    }

    ostringstream os;
    for(const auto &entry: people){
        ostringstream formatted, badNums;
        for(const auto &nums: entry.phones){
            if(!valid(nums)){
                badNums << " " << nums;   // 将数的字符串形式存入badNums中
            }
            else{
                // 将格式化的字符串“写入”formatted
                formatted << " " << format(nums);
            }
        }
        if(badNums.str().empty()){   // 没有错误的数
            os << entry.name << " " << formatted.str() << endl;   // 打印名字和格式化的数
        }
        else{
            cerr << "input error: " << entry.name << "invalid number(s) " << badNums.str() << endl; 
        }
    }
    cout << os.str() << endl;

    return 0;
}
```

```shell
eason@eason:~/cpp_primer/chapter8$ g++ phone.cpp -o phone
eason@eason:~/cpp_primer/chapter8$ ./phone phone.txt 
morgan  2015552368 8625550123
drew  9735550130
lee  6095550132 2015550175 8005550000

```










