/*
手写快速排序
*/
#include <bits/stdc++.h>
using namespace std;
int part(vector<int>& a,int l,int r){
    int i = l,j = r,mask = a[l];
    while(i < j){
        while(a[j] > mask) j--;
        if(i < j) swap(a[i++],a[j]);
        while(a[i] <= mask) i++;
        if(i < j) swap(a[i],a[j--]);
    }
    return i;
}
void quick_sort(vector<int>& a,int l,int r){
    if(l < r){
        int mid = part(a,l,r);
        quick_sort(a,l,mid-1);
        quick_sort(a,mid+1,r);
    }
}
void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}