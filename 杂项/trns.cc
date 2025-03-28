#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[5] = {1,2,3,4,5};
    int b[5] = {};
    transform(a,a+5,b,[&](int x){return x += 1;});
    for(int i=0;i<5;i++){
        cout << a[i] << " \n"[i==4];
    }
    for(int i=0;i<5;i++){
        cout << b[i] << " \n"[i==4];
    }
    
    return 0;
}