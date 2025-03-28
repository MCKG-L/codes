#include <bits/stdc++.h>
using namespace std;
/*
1、差分数组的作用：可以将区间操作转化为单点操作，最后再其差分数组的前缀和得到答案数组
2、求差分数组时不要直接用原数组覆盖值，应该另外开一个差分数组，求前缀和数组可以用原数组
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin >> n;
    vector<int> a(n+1),d(n+2);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        d[i] = a[i] - a[i-1];
    }
    int l,r,v;
    while(cin >> l >> r >> v){
        d[l] += v;
        d[r+1] -= v;
    }
    for(int i=1;i<=n;i++){
        a[i] = d[i] + a[i-1];
        cout << a[i] << " \n"[i==n];
    }
    return 0;
}