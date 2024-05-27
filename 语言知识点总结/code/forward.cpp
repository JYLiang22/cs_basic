#include <iostream>
#include <utility>

void Print(int& val) {
    std::cout << "lvalue refrence: val=" << val << std::endl;
}

void Print(int&& val) {
    std::cout << "rvalue refrence: val=" << val << std::endl;
}

template<typename T>
void TPrint(T &&t) {
    // return Print(t);
    return Print(std::forward<T>(t));
}

int main() {
    int date = 1021;
    TPrint(date);
    TPrint(501);

    return 0;
}
