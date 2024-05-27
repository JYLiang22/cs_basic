/*
* @date : 2024.5.27
* @author : JYLiang
* @brief    
*/

#include"Virtual_Table.h"

int main(){

    DDerived derived;
    derived.g();

    /* 1
    Base base;
    Fun fun = nullptr;

    std::cout << "address of pointer point to virtual table:" << (long*)(&base) << std::endl;
    std::cout << "address of virtual table:" << (long*)*(long*)(&base) << std::endl;

    std::cout << "offset_to_top:" << *((long*)*(long*)(&base) - 2) << std::endl;
    std::cout << "typeinfo for Base:" << (long*)*((long*)*(long*)(&base) - 1) << std::endl;

    fun = (Fun)*((long*)*(long*)(&base));
    std::cout << "address of the first func in virtual table:" << (long*)fun << std::endl;
    fun();

    fun = (Fun)*((long*)*(long*)(&base) + 1);
    std::cout << "address of the second func in virtual table:" << (long*)fun << std::endl;
    fun();

    fun = (Fun)*((long*)*(long*)(&base) + 2);
    std::cout << "address of the third func in virtual table:" << (long*)fun << std::endl;
    fun();
    */
}
