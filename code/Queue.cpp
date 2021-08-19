#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class Queue
{
    public:
    Queue();
    ~Queue();
    void push(int x);
    void pop();
    int front();
    int back();
    int size();
    bool isempty();
    void Print();
    private:
    Node* Head;
};
Queue::Queue()
{
    Head=new Node;
    Head->next=NULL;
}
Queue::~Queue()
{
    Node* ptr;
    while(Head)
    {
        ptr=Head;
        Head=Head->next;
        delete ptr;
    }
    Head=NULL;
}
void Queue::push(int x)
{
    Node* ptr=new Node;
    ptr->data=x;
    ptr->next=Head->next;
    Head->next=ptr;
}
void Queue::pop()
{
    if(isempty())
   { cout<<"Queue is empty"<<endl;
   return;
   }
    Node* ptr=Head->next;
    Node* p=Head;
    while(ptr->next!=NULL)
    {ptr=ptr->next;
    p=p->next;
    }
    p->next=NULL;
    delete ptr;

}
bool Queue::isempty()
{
    return Head->next==NULL;
}
int Queue::size()
{
    if(isempty())
    return 0;
    int count=0;
   Node* ptr=Head;
   while(ptr->next!=NULL)
   {ptr=ptr->next;
   count++;
   }
   return count;

}
int Queue::back()
{
    if(isempty())
    return -1;
    return Head->next->data;
}
int Queue::front()
{
    if(isempty())
    return -1;
    Node* ptr=Head;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    return ptr->data;

}
void Queue::Print()
{
    Node* ptr=Head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        cout<<ptr->data<<' ';
    }
}
int main()
{
    Queue Q;
    int n=5;
    while(n--)
    {
        int x;
        cin>>x;
        Q.push(x);
    }
    Q.Print();
    Q.pop();
    Q.Print();
    cout<<Q.size()<<Q.back()<<Q.front()<<Q.isempty();
    system("pause");
    return 0;
}