#include <iostream>
#include <algorithm>
using namespace std;
// 五类二分问题
// 1、找到target的位置
int f1(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] == x) return mid + 1;
        if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
// 2、找到大于x的第一个位置
int f2(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return l >= n ? -1 : l;
}
// 3、找到大于等于x的第一个位置
int f3(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l >= n ? -1 : l;
}
// 4、找到小于x的最后一个位置
int f4(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return r < 0 ? -1 : r;
}
// 5、找到小于等于x的最后一个位置
int f5(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    return r < 0 ? -1 : r;
}
// 6、找到x出现的最后一个位置
int f6(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    return (r < 0 || a[r] != x) ? -1 : r;
}
// 7、找到x出现的第一个位置
int f7(int a[],int n,int x){
    int l = 0,r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    return (l >= n || a[l] != x) ? -1 : l;
}
int main()
{
    int n;cin >> n;
    int a[n] = {};
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) cout << a[i] << ' ' ;
    cout << endl;
    int q;cin >> q;
    while(q--){
        int x;cin >> x;
        // cout << m_binary(a,n,x) << endl;
        cout << x << "出现的位置：" << f7(a,n,x) + 1 << ' ' << f6(a,n,x) + 1 << endl;
        cout << "大于" << x << "的第一个位置：" << f2(a,n,x) + 1 << endl;
        cout << "大于等于" << x << "的第一个位置：" << f3(a,n,x) + 1 << endl;
        cout << "小于" << x << "的最后一个位置：" << f4(a,n,x) + 1 << endl;
        cout << "小于等于" << x << "的最后一个位置：" << f5(a,n,x) + 1 << endl;
    }
    return 0;
}