#include <iostream>
#include <algorithm>
using namespace std;
//01模型 返回第一次出现的位置
int m_binary(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    // if(a[l] == x) return l;
    // return -1;
    return l;
}
int f1(int a[],int n,int x){
    int l = 0,r = n-1;
    while(l <= r){
        int mid = l + r >> 1;
        if(a[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    
    return l;
}
int f2(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l <= r){
        int mid = l + r >> 1;
        if(a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return r;
}
int find(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}
int find2(int a[],int n,int x){
    int l = 0,r = n-1;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
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
        // int p = lower_bound(a,a+n,x)-a;
        cout << f1(a,n,x) << ' ' << f2(a,n,x) << endl;
        // cout << p << endl;
        // cout << m_binary(a,n,x) << endl;
    }
    return 0;
}