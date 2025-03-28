#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n,a[N],t[N];
void merge_sort(int l,int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l,mid),merge_sort(mid+1,r);
    int k = 0,i = l,j = mid + 1;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) t[k++] = a[i++];
        else t[k++] = a[j++];
    }
    while(i <= mid) t[k++] = a[i++];
    while(j <= r) t[k++] = a[j++];
    k = 0;
    for(int i=l;i<=r;i++) a[i] = t[k++];
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    merge_sort(0,n-1);
    for(int i=0;i<n;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}