#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
class Stack
{
public:
	Stack();
	~Stack();
	void push(int x);
	void pop();
	int top();
    bool isempty();
    void Print();
 
private:
	Node *Head;
};
Stack::Stack()
{
    Head=new Node;
    Head->next=NULL;
}
Stack::~Stack()
{
   Node* ptr;
   ptr=Head->next;
   while(Head)
   {
   ptr=Head;
   Head=Head->next;
   delete ptr;
   }
   Head=NULL;
}

 void Stack::push(int x)
 {
    Node* node=new Node;
    node->data=x;
    node->next=Head->next;
    Head->next=node;
 }
 void Stack::pop()
 {
     if(!isempty())
     {
         Node* ptr=Head->next;
         Head->next=ptr->next;
         delete ptr;
     }
     else
     {
         cout<<"stack is empty"<<endl;
     }   
 }
 bool Stack::isempty()
 {
     return Head->next==NULL;
 }
 int Stack::top()
 {
     if(!isempty())
     {
         cout<<Head->next->data<<endl;
     }
     else
     {
         cout<<"stack is empty"<<endl;
     }
     
 }
 void Stack::Print()
 {
     Node* ptr=Head;
     while(ptr->next)
     {
         cout<<ptr->next->data<<' ';
         ptr=ptr->next;
     }
 }
int main()
{
    Stack S;
    int n=5;
    while(n--)
   { int x;
    cin>>x;
    S.push(x);}
    S.pop();
    S.Print();
    cout<<S.isempty();
system("pause");
	return 0;
}