#include <bits/stdc++.h>
using namespace std;
//找到有序数组中最后一次出现某元素的位置，不存在返回-1
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
    int n,m,x;cin >> n >> m;
    int a[n] = {};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    while(m--){
        cin >> x;
        cout << m_binary(a,n,x) << endl;
    }
    return 0;
}