#include<iostream>
using namespace std;
#if 0
int main(int argc, char const *argv[])
{
    int i,j,k,f;
    for (i=1;i<=4;i++){
        for (j=1;j<=30;j++)
            cout<<" ";
        for (k=1;k<=8-2*i;k++)
            cout<<" ";
        for (f=1;f<=2*i;f++)
            cout<<'*';
        cout<<endl;
    }
    for(i=1;i<=3;i++){
        for (j=1;j<=30;j++)
            cout<<" ";
        for (f=1;f<=7-2*i;f++)
            cout<<'*';
        cout<<endl;
    }
    system("pause");
    return 0;
}



//相同的内存地址
union myun 
{
    struct { int x; int y; int z; }u; 
    int k; 
}a; 
int main() 
{ 
    a.u.x =4;
    a.u.y =5; 
    a.u.z =6; 
    a.k = 0; //覆盖掉第一个int空间值
    printf("%d %d %d %d\n",a.u.x,a.u.y,a.u.z,a.k);
    system("pause");
    return 0;
}

#endif

union data{
    int n;
    char ch;
    short m;
};

int main(){
    union data a;
    printf("%d, %d\n", sizeof(a), sizeof(union data) );
    a.n = 0x40;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.ch = '9';
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.m = 0x2059;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.n = 0x3E25AD54;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
   system("pause");
    return 0;
}