#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int a[N],temp[N],n;
void merge_sort(int l,int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l,mid),merge_sort(mid+1,r);
    int k = 0,i = l,j = mid + 1;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    k = 0;
    for(int i=l;i<=r;i++) a[i] = temp[k++];
}
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    merge_sort(0,n-1);
    for(int i=0;i<n;i++) cout << a[i] << ' ';
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}