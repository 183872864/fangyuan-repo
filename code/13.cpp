/*机器人的运动范围*/
#include <bits/stdc++.h>
using namespace  std;
int Count(int target,int rows,int cows,int row,int cow,bool *visit);
bool check(int target,int rows,int cows,int row,int cow,bool *visit);
int getdigit(int number);

int movecount(int target,int rows,int cows)
{
    if(target<0||cows<=0||rows<=0)return 0;
    bool *visit = new bool[rows * cows];
    for(int i = 0; i < rows * cows; ++i)
        visit[i] = false;
   int count=Count(target,rows,cows,0,0,visit);
   return count;
}

int Count(int target,int rows,int cows,int row,int cow,bool *visit)
{
    int count=0;
    if(check(target,rows,cows,row,cow,visit))
    {
        visit[row*cows+cow]=true;
        count=1+Count(target,rows,cows,row-1,cow,visit)+Count(target,rows,cows,row,cow-1,visit)
        +Count(target,rows,cows,row+1,cow,visit)+Count(target,rows,cows,row,cow+1,visit);

    }
    cout<<count<<endl;
    return count;
}

bool check(int target,int rows,int cows,int row,int cow,bool *visit)
{
     if(row >= 0 && row < rows && cow >= 0 && cow < cows
        && getdigit(row) + getdigit(cow) <= target
        && !visit[row* cows + cow])
        return true;

    return false;
}

int getdigit(int number)
{
    int sum=0;
    while(number>0)
    {
     sum+=number%10;
     number/=10;
    }
    return  sum;

}
int main(){
    cout<<movecount(2,3,3);
    getchar();
    return 0;
}