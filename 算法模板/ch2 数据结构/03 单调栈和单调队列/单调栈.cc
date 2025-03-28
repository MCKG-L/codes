#include <iostream>
using namespace std;
/*
使用场景 求一个序列中每一个数左边离其最近且比其小的数，没有则为-1
序列：3  4  2  7  5
答案：-1 3  -1 2  2
*/
const int N = 100010;
int stk[N],tt;
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        while(tt && stk[tt] >= x) tt--;
        if(tt) cout << stk[tt] << ' ';
        else cout << -1 << ' ';
        stk[++tt] = x;
    }
    return 0;
}