#include <iostream>
using namespace std;
//算法思想 ： 分治法
const int N = 1e6 + 10;
int n,a[N];
void quick_sort(int a[],int l,int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    int x = a[mid],i = l - 1,j = r + 1;
    while(i < j){
        do i++;while(a[i] < x);
        do j--;while(a[j] > x);
        if(i < j) swap(a[i],a[j]);
    }
    quick_sort(a,l,j);
    quick_sort(a,j+1,r);
}
void quick_sort(int l,int r){
    if(l >= r) return;
    int x = a[l],i = l - 1,j = r + 1;
    while(i < j){
        do i ++;while(a[i] < x);
        do j --;while(a[j] > x);
        if(i < j) swap(a[i],a[j]);
    }
    quick_sort(l,j);
    quick_sort(j + 1,r);
}
int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}