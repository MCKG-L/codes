#include <iostream>
#include <algorithm>
using namespace std;
/*
使用快速选择算法获取第K小的数

快速排序的思想

有库函数
*/
const int N = 100010;
int n,k;
int q[N];
int quick_sort(int l,int r,int k){
    if(l == r) return q[l];
    int x = q[l],i = l - 1,j = r + 1;
    while(i < j){
        do i++;while(q[i] < x);
        do j--;while(q[j] > x);
        if(i < j) swap(q[i],q[j]);
    }
    int s = j - l + 1;
    if(k <= s) return quick_sort(l,j,k);
    return quick_sort(j+1,r,k-s);
}
int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> q[i];
    cout << quick_sort(0,n-1,k) << endl;
    return 0;
}