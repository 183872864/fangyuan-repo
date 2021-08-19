#include<bits/stdc++.h>
using namespace std;
class List {
     int data;
     List *next;
     public:
     List(int x) : data(x), next(NULL) {}
     List* create(int len);
     int getlength(List* list);
     bool isempty(List* list);
     void Print(List* list);
     List* insert(List* list,int n,int data);
     List* Delete(List* list,int n);
  };
  void List::Print(List* list)
  {
      List* node=list;
      while (node!=NULL)
      {
          cout<<node->data<<' ';
          node=node->next;
          
      }
      return;
      
  }
 List* List::create(int len)
  {
      List* head=new List(0);
      List *p,*q=head;
       
      while(len--)
      {
        int data;
          cin>>data;
        p=new List(data);
          q->next=p;
          q=p;
      }
      return head->next;
  }

  bool List::isempty(List* list)
  {
      if(list==NULL)
      return true;
      else;
      return false;
  }
  
  int List::getlength(List* list)
  {
      List* head=list;
      int count=0;
      while(!this->isempty(head))
      {
          head=head->next;
          count++;
      }
      return count;
  }
  List* List::insert(List* list,int n,int data)
  {
      List* node=list;
       if(this->isempty(list))
       {
           list->data=data;
           return list;
       }
       if(this->getlength(list)<n)
       {
           while(node->next!=NULL)
           {
              node=node->next;
           }
           List* lnode=new List(data);
           node->next=lnode;
           return list;
       }
       n--;
       while(n--)
       {
           node=node->next;

       }
       List* lnode=new List(data);
           lnode->next=node->next;
           node->next=lnode;
           return list;

  }
  List* List::Delete(List* list,int n)
  {
      List* node=list;
    if(list==NULL)
    return list;
    if(this->getlength(node)<n)
    return list;
      List* p=list;
      if(n==1)
      {
          list=list->next;
      }
      
      else{
          n=n-2;
           while(n--)
      {
          node=node->next;
      }
      p=node->next;
      node->next=p->next;
      delete p;
      }
      return list;
      
  }
int main()
{
    int n,m;
    cin>>n;
    List* node;
    List tmp(0);
    node=tmp.create(n);
    tmp.Print(node);
    cout<<tmp.getlength(node)<<endl;
    tmp.Print(tmp.Delete(node,1));
    system("pause");
    return 0;
}