/*
* @date : 2024.5.27
* @author : JYLiang
* @brief
    分别验证了单继承无虚函数覆盖的情况
    单继承有虚函数覆盖的情况
    多重继承的情况
    多层继承的情况
*/

#include<iostream>
#include<string>
using namespace std;

// typedef void (*Fun)(void);   // 1

class Base{
public:
    virtual void f(){
        cout << "Base::f()" << endl;
    }

    virtual void g(){
        cout << "Base::g()" << endl;
    }

    virtual void h(){
        cout << "Base::h()" << endl;
    }
};

class Derived : public Base{
public:
    virtual void f1(){
        std::cout << "Derived::f1()" << std::endl;
    }

    virtual void g(){
        std::cout << "Derived::g1()" << std::endl;
    }

    virtual void h1(){
        std::cout << "Derived::h1()" << std::endl;
    }
};

class DDerived : public Derived{
public:
    virtual void f(){
        std::cout << "DDerived::f()" << std::endl;
    }

    virtual void h(){
        std::cout << "DDerived::h()" << std::endl;
    }

    virtual void g2(){
        std::cout << "DDerived::g2()" << std::endl;
    }
};