#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];
int m_find(int x,int n){
    int l = 0,r = n - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(a[mid] >= x){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    if(a[l] == x) return l + 1;
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    // sort(a,a+n);
    while(m--){
        int x;cin >> x;
        cout << m_find(x,n) << " ";
    }
    return 0;
}