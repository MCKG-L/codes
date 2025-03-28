#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100010;
int n;
int q[N],temp[N];
ll merge_sort(int l,int r){
    if(l >= r) return 0;
    int mid = l + r >> 1;
    ll ans = merge_sort(l,mid) + merge_sort(mid + 1,r);
    //merge
    int k = 0,i = l,j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] < q[j]) temp[k++] = q[i++];
        else{
            temp[k++] = q[j++];
            ans += mid - i + 1;
        }
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];

    for(int i=l,j=0;i<=r;i++,j++) q[i] = temp[j];
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> q[i];
    // cout << merge_sort(0,n-1) << endl;
    int ans = merge_sort(0,n-1);
    ans %= 2;//保留总逆序对数的奇偶性
    int m;cin >> m;
/*
反转区间[l,r] [l,r]范围内逆序对数变为原顺序对数
设[l,r]逆序对数为x 则顺序对数为 (r-l+1)*(r-l)/2 - x
反转后总序列的逆序对数：sum =  ans + (r-l+1)*(r-l) - 2x
可以看出影响总逆序对数奇偶性的是 ans 和 (r-l+1)*(r-l)/2
如果(r-l+1)*(r-l)/2为奇数 则总逆序对数的奇偶性发生改变
*/
    while(m--){
        int l,r;
        cin >> l >> r;
        int s = r - l + 1;//反转区间的长度
        if((s*(s-1)/2) % 2) ans ^= 1;
        if(ans) puts("dislike");
        else puts("like");
    }
    return 0;
}