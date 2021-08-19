#include<bits/stdc++.h>
using namespace std;
bool help(const char* matrix,int rows,int cows,int row,int cow,int len,const char* str,vector<bool> visit);
bool helps(const char* matrix,int rows,int cows,const char* str)
{
    if(matrix==nullptr||rows<1||cows<1||str==nullptr) return false;
    vector<bool> visit(rows*cows,false);
    int len=0;
    for(int row=0;row<rows;row++)
    {
        for(int cow=0;cow<cows;cow++)
        {
            if(help(matrix,rows,cows,row,cow,len,str,visit))return true;
        }
    }
    return false;
}
bool help(const char* matrix,int rows,int cows,int row,int cow,int len,const char* str,vector<bool> visit)
{
    if(str[len]=='\0')return true;
      
      bool flag=false;
      if(row >= 0 && row < rows && cow >= 0 && cow < cows
        && matrix[row * cows + cow] == str[len]
        && !visit[row * cows + cow])
        {
            len++;
            visit[row*cows+cow]=true;
        flag=help(matrix,rows,cows,row-1,cow,len,str,visit)||help(matrix,rows,cows,row,cow-1,len,str,visit)
        ||help(matrix,rows,cows,row+1,cow,len,str,visit)||help(matrix,rows,cows,row,cow+1,len,str,visit);
        if(!flag)
        {
            len--;
            visit[row*cows+cow]=false;
        }
        }
        return flag;
}
int main()
{
   const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";
    bool flag=helps(matrix,3,4,str);
    
    cout<<flag<<endl;
    getchar();
    return 0;
}