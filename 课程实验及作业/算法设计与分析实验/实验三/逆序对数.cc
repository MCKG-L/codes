#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int tr[N],n;
int temp[N];
int lowbit(int x){
    return x & -x;
}
void add(int x,int c){
    for(int i=x;i<=n;i+=lowbit(i)){
        tr[i] += c;
    }
}
int sum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i)) ans += tr[i];
    return ans;
}

ll merge_sort(vector<int> &a,int l,int r){
    if(l >= r) return 0;
    int ans = 0;
    int mid = (l + r) / 2;
    ans = merge_sort(a,l,mid) + merge_sort(a,mid+1,r);
    int i = l,j = mid + 1,k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) temp[k++] = a[i++];
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
    vector<int> a(n),b;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    b = a;
    // sort(a.begin(),a.end());
    // a.erase(unique(a.begin(),a.end()),a.end());
    // auto find = [&](int x) -> int {
    //     return lower_bound(a.begin(),a.end(),x)-a.begin()+1;
    // };
    // ll ans = 0;
    // for(int i=n-1;i>=0;i--){
    //     int x = find(b[i]);
    //     ans += sum(x-1);
    //     add(x,1);
    // }
    // cout << ans << endl;
    cout << merge_sort(a,0,n-1) << endl;
    return 0;
}