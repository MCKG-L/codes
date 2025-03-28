#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N],temp[N];
int n;
ll merge_sort(int l,int r){
    if(l >= r) return 0;
    int mid = l + r >> 1;
    ll ans = merge_sort(l,mid) + merge_sort(mid+1,r);
    int i = l,j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) temp[k++] = a[i++];//这里改为大于等于
        else{
            ans += mid - i + 1;
            temp[k++] = a[j++];
        }
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    k = 0;
    for(int i=l;i<=r;i++) a[i] = temp[k++];
    return ans;
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cout << merge_sort(0,n-1) << endl;
    return 0;
}