#include <bits/stdc++.h>
using namespace std;
void printnumber(char* number)
{
    bool flag=true;
    int len=strlen(number);
    for(int i=0;i<len;i++)
   { if(flag&&number[i]!=0)
   {
       flag=false;
   }
   if(!flag)
   cout<<number[i];
}
cout<<' ';
}

void findbig(char* number,int n,int index)
{
    if(index==n-1)
   { printnumber(number);
   return ;
   }
    for(int i=0;i<10;i++)
    {
        number[index+1]=i+'0';
        findbig(number,n,index+1);
    }
}

void printmax(int n)
{
    if(n<=0)return ;
    char bigdigit[n+1]={0};
    bigdigit[n]='\0';
    for(int i=0;i<n;i++)
    {
        bigdigit[0]=i+'0';
        findbig(bigdigit,n,0);
    }
}

int main()
{
  int n;
  cin>>n;
  printmax(n);
  getchar();
  return 0;
}