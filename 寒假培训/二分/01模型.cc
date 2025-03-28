#include <bits/stdc++.h>
using namespace std;
//查找有序数组中元素第一次出现的位置，不存在返回-1
int m_binary(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if(a[l] == x) return l;
    return -1;
}
int main()
{
    int n;cin >> n;
    int a[n] = {};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int m,x;
    cin >> m;
    while(m--){
        cin >> x;
        cout << m_binary(a,n,x) << endl;
    }
    return 0;
}