#include <bits/stdc++.h>
using namespace std;

int f1(unsigned x){
    return (int)((x << 24) >> 24);
}

int f2(unsigned x){
    return ((int)x << 24) >> 24;
}

int main()
{
    int a[] = {127,128,255,256};
    for(int i=0;i<4;i++){
        cout << f1(a[i]) << endl;
    }
    for(int i=0;i<4;i++){
        cout << f2(a[i]) << endl;
    }
    return 0;
}