#include <bits/stdc++.h>
using namespace std;
int main()
{
    const int * a;
    int c = 10;
    int r = 1000;
    int * const d =&c;
    * d = 100;
    int const * b;
    a = &c;
    cout<<*d;
    getchar();
    return 0;
}