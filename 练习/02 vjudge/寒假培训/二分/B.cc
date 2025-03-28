#include <bits/stdc++.h>
using namespace std;
int m_find(int a[],int x,int n){
    int l = 0,r = n - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(a[mid] >= x){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    if(a[l] == x) return l + 1;
    return -1;
}
void solve(){
    int n,m;
    cin >> n >> m;
    int a[n] = {};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    while(m--){
        int x;
        cin >> x;
        cout << m_find(a,x,n) << " \0"[m == 0];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}