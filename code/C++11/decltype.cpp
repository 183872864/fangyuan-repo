#include<iostream>
using namespace std;
class A
{
    public:
    A() = default;
    A(int a) = default;

    A& operator = (const operator&);
}