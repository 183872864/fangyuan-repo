#include<iostream>

using namespace std;

void lvalcite()  //左值引用test
{
    std::string s;
    std::string& str = s;//str为左值引用

//  std::string& r = **std::string()**;  非常量引用的初始值必须为左值
    const std::string& r = std::string();  //  √
    cout << "do nothing" <<endl;
}

int main()
{
    lvalcite();
    return 0;
}