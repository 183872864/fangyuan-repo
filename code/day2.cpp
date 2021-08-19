#include<iostream>
using namespace std;
#if 0
double power(double x, int n);

int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    int n ,m ;
    int wei = 0,sum =0;
    for(int i = 0; i < 8; i++)
{
    n = x%10;
    m=x/10;
    sum += n*power(2,wei);
    wei++;
    x = m;
}
    cout << sum <<endl;
    system("pause");
}

double power(double a, int b)
{
    double val = 1.0;
    while(b--)
    {
        val*=a;
    }
    return val;
}
#endif

void move (char a,char b);
void hanoi(int d,char a,char b,char c);

int main(){
    int d;
    cin>> d;
    hanoi(d,'a','b','c');
    system("pause");
    return 0;
}

void move(char a,char b){
    cout<<"move "<<a<< "->"<<b<<endl;
}
void hanoi(int d,char a,char b,char c)
{
    if(d==1)
    move(a,c);
    else
    {
        hanoi(d-1,a,b,c);
        move(a,c);
        hanoi(d - 1, b, a, c);
    }
}