#include <bits/stdc++.h>
using namespace std;
/*
    二分答案
*/
int m_find(int a[],int n,int k){
    int l = 0,r = a[n-1];
    while(l < r){
        int mid = (l + r + 1) / 2;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += a[i]/mid;
        }
        if(sum < k){
            r = mid - 1;
        }else{
            l = mid;
        }
    }
    if(l < 1) return 0;
    return l;
}
void solve(){
    int n,k;
    cin >> n >> k;
    int a[n] = {};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    cout << m_find(a,n,k);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}