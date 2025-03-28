#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
//求最大上升子序列
//dilworth定理 最少不上升子序列个数等于最大上升子序列长度
struct s{
    int l,w;
}a[N];
bool cmp(s a,s b){
    if(a.l == b.l) return a.w > b.w;
    else return a.l > b.l;
}
int main()
{
    int n;cin >> n;
    int mp[n] = {};
    //mp[i] 表示以i结尾的最大上升子序列长度
    for(int i=0;i<n;i++) {
        cin >> a[i].l >> a[i].w;
        mp[i] = 1;
    }
    int ans = INT_MIN;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j].w < a[i].w){
                mp[i] = max(mp[i],mp[j] + 1);
            }
        }
    }
    for(int i=0;i<n;i++){
        ans = max(ans,mp[i]);
    }
    cout << ans;
    return 0;
    
}