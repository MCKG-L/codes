#include <iostream>
#include <algorithm>
using namespace std;
int m_binary(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    if(a[l] == x) return l;
    return -1;
}
int main()
{
    int n;cin >> n;
    int a[n] = {};
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int q;cin >> q;
    while(q--){
        int x;cin >> x;
        cout << m_binary(a,n,x) << endl;
    }
    return 0;
}