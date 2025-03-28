#include <bits/stdc++.h>
using namespace std;
/*
本题求的是序列的逆序对数，也即是进行冒泡排序时进行的交换次数
*/
void solve(){
    int n;cin >> n;
    int a[n] = {};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int mask = 0,ans = 0;
    for(int i=0;i<n-1;i++){
        mask = 1;
        for(int j=0;j<n-1-i;j++){
            if(a[j] > a[j+1]){
                ans ++;
                swap(a[j],a[j+1]);
                mask = 0;
            }
        }
        if(mask) break;
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}