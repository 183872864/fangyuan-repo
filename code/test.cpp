#include <iostream>
using namespace std;
int main() {
    int a,b;
    int map[3] = {0};
   
    for(int i=0;i<3;i++)
    {
    	cout<<map[2]<<endl;
        for(int j=0;j<3;j++)
        {
            cout<<j<<map[j]<<endl;
            map[j]++;
        
        }
    }
}
