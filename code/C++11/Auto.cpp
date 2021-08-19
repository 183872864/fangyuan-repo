#include<iostream>
using namespace std;

int y = 10;
// void func(auto x = y);   //此处不允许使用,即不能用作函数参数推导

struct foo
{
    static const int y = 0;
//  static /*const*/ auto val = 0;      //在类中auto不能用作非静态成员变量   
};

int main()
{
  int i;
    auto a = i, &b = i, *c = &i; // a是int，b是i的引用，c是i的指针，auto就相当于int
//  auto d = 0, f = 1.0; // error，0和1.0类型不同，对于编译器有二义性，没法推导
//  auto e; // error，使用auto必须马上初始化，否则无法推导类型

    int x;
    auto *a = &x;
    auto b = &x;
    auto& c = x;
    auto d = c;

    const auto e = x;

    auto f1 = e;
    const auto& g = x;
    auto& h = g;

    return 0;
}