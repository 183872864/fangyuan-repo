#include<iostream>
#include<vector>
using namespace std;

struct X {
   int a;
   int b;
   int c;
   
};

struct Y {
int a;
   int b;
   virtual void func() {} // 含有虚函数，不是聚合类
};
 
 
struct Base {};
struct B : public Base { // 有基类，不是聚合类
int a;
   int b;
};
 
 
struct C {
   int a;
   int b = 10; // 有等号初始化，不是聚合类
};
 
 
struct D {
   int a;
   int b;
private:
   int c; // 含有私有的非静态数据成员，不是聚合类
};
 
 
struct E {
int a;
   int b;
   E() : a(0), b(0) {} // 含有默认成员初始化器，不是聚合类
};

struct A {
public:
   A(int) {}
private:
    A(const A&) {}
};

//列表初始化也可以用在函数的返回值上
std::vector<int> func() {
   return {};
}
int main() {
   A a(123);
   A b = 123; // error
   A c = { 123 };
   A d{123}; // c++11
   
   int e = {123};
   int f{123}; // c++11
   
   X x{1,2,3};// error，X有自定义的构造函数，不能列表初始化

   return 0;
}