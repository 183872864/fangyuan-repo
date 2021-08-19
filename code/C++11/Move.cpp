#include<iostream>
#include<list>
using namespace std;

//move 语义
//移动语义，可以理解为转移所有权，之前的拷贝是对于别人的资源，自己重新分配一块内存存储复制过来的资源
//而对于移动语义，类似于转让或者资源窃取的意思，对于那块资源，转为自己所拥有，别人不再拥有也不会再使用
//通过C++11新增的移动语义可以省去很多拷贝负担
//std::move 等价于static_cast<T&&>(lvalue);  左值转右值
//对基本类型无效

class A {
public:    
A(int size) : size_(size) 
{      
    data_ = new int[size];   
}    
A(){}    
A(const A& a) {        
    size_ = a.size_;        
    data_ = new int[size_];        
    cout << "copy " << endl;    }    
A(A&& a) {        
    this->data_ = a.data_;        
    a.data_ = nullptr;        
    cout << "move " << endl;    }    
~A() {        
    if (data_ != nullptr) 
		{         delete[] data_;        }  
		}    
    int *data_;    
    int size_;
			};
int main() 
{    
    A a(10);    
    A b = a;    
    A c = std::move(a); // 调用移动构造函数    
    return 0;
}