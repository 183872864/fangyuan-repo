#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int N;
    cin>>N;
    unordered_map<int,int> ans;
    while(N--)
    {
        int pre=0;
        ans[0]++;
        int a,b,m,n=1;
        cin>>a>>b>>m;
        while(1)
        {
        int y=(a*pre+b)%m;
        pre=y;
         if(ans.count(y)==0)
         {
             
             ans[y]++;
             n++;
         }
        else 
        break;
    }
    for(int i=1;i<=n;i++)
    {
        if(ans.count(i)==0)
       { cout<<i<<endl;
       break;
       }
    }
    ans.clear();
 }
    return 0;
}