#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int func(int n){
    map<int,int> cnt;
    for(int i=0;i<4;i++){
        int r = n % 10;
        cnt[r]++;
        n /= 10;
    }
    return cnt.size();
}
int main()
{
    int x,n;cin >> x >> n;
//     cout << func(x);
    int k = 0;
    while(func(x+k) != n) k++;
    printf("%d %04d\n",k,x+k);
    return 0;
}