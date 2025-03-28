#include <bits/stdc++.h>
using namespace std;
int m_find(int a[],int x,int m){
    int l = 0,r = m - 1;
  //  if(a[m-1] < x)return x - a[m-1];
    while(l < r){
        int mid = (l + r) / 2;
        if(a[mid] < x){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    if(l == 0) return a[0] - x;
    //注意如果l == m - 1时对应两种情况：
    //1、所有元素均小于x
    //2、找到的位置就是m - 1
    return min(abs(a[l]-x),abs(x-a[l-1]));
    //或者：
    // int i = lower_bound(a,a+m,x) - a;
    // if(i == m){
    //     return x - a[m-1];
    // }else if(i == 0){
    //     return a[0] - x;
    // }
    // return min(a[i]-x,x-a[i-1]);
}
void solve(){
    int m,n;
    cin >> m >> n;
    int a[m] = {};
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    sort(a,a+m);
    long long ans = 0;
    while(n--){
        int x;
        cin >> x;
        ans += m_find(a,x,m);
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