#include<iostream>

using namespace std;

//C++11特性
//左值右值
void PrintV(int &t) {
    cout << "lvalue" << endl;
}

void PrintV(int &&t) {
    cout << "rvalue" << endl;
}

void lvalcite()  //左值引用test
{
    std::string s;
    std::string& str = s;//str为左值引用

//  std::string& r = **std::string()**;  非常量引用的初始值必须为左值
    const std::string& r = std::string();  //  √
    cout << "do nothing" <<endl;
}

void rvalcite() //右值引用test
{
    
}

template<typename T>
void Test(T &&t) {
    PrintV(t);
    PrintV(std::forward<T>(t));
    PrintV(std::move(t));
}

int main() {
    Test(1); // lvalue rvalue rvalue
    int a = 1;
    Test(a); // lvalue lvalue rvalue
    Test(std::forward<int>(a)); // lvalue rvalue rvalue
    Test(std::forward<int&>(a)); // lvalue lvalue rvalue
    Test(std::forward<int&&>(a)); // lvalue rvalue rvalue
    system("pause");
    return 0;
}
