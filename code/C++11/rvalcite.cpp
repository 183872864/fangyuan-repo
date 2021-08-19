#include<iostream>

int g_contor_count = 0;
int g_copycontor_count = 0;
int g_destor_count = 0;

struct A
{
    A(){  std::cout << "A::A()" << ++g_contor_count << std::endl;}

    A(const A&a)
    {
        std::cout << "A::A(const A&)" << ++g_copycontor_count << std::endl;
    }

    ~A()
    {
        std::cout << "A::~A()" << ++g_destor_count << std::endl;
    }
};

class B
{
    public:
    B() : ptr_(new int(0))
    {
        std::cout << "构造函数。。。" << std::endl;
        }
    B(const B&b) : ptr_(new int(*b.ptr_))
    {
        std::cout << "拷贝构造。。。" << std::endl;
    }

    B(B&& b) : ptr_(b.ptr_)
    {
        b.ptr_ = nullptr;
        std::cout << "移动拷贝构造。。。" << std::endl;
    }
    const B& operator = (B&& a)
    {
        delete ptr_;
        ptr_ = b.ptr_;
        b.ptr_ = nullptr;
        std::cout << "移动复制。。。" << std::endl;
        return *this;
    }

    ~B()
    {
        std::cout << "析构函数。。。" << std::endl;
        delete ptr_;
    }
    public:
    int *ptr_;
};

B get(bool flag)
{
    B a;
    B b;
    if(flag)
      return a;
    else
      return b;
}

template<typename T>
T getA()
{
    return T();
}

int main()
{
    A a1 = getA<A>();
    std::cout<<std::endl;
    A &&aa = getA<A>();
    
    std::cout<<std::endl;
    B b1;
    B b = get(false);
    std::cout<<std::endl;
    B bb = b1;
    system("pause");
    return 0;
}