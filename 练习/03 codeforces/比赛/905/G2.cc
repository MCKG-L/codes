#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int a[N],b[N],c[N];
int n,m;
/*
a[1]取1~m，求所有答案的和
设a[1] == 1时答案为ans，则当a[1]增大时会出现两种情况：
1、a[1]比较小，不需要删除这个数，答案和ans相同
2、a[1]比较大，需要删除这个数才能满足题目条件，则答案为ans + 1
3、不论a[1]多么大，只要把它删除了，剩下的序列，需要删除的个数一定不大于a[1] == 1时的情况
4、所以a[1] 取1~m时，答案具有单调性，当a[1] <= x时，答案为ans，a[1] > x时 答案为ans + 1

*/
bool check(int mid){
    for(int i=1;i<=n-mid;i++){
        if(a[i] >= b[mid+i]) return 0;
    }
    return 1;
}
void solve(){
    cin >> n >> m;
    a[1] = 1;
    for(int i=2;i<=n;i++) cin >> a[i],c[i] = a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    sort(a+1,a+n+1),sort(b+1,b+1+n);
    int ans = n + 1;
    int l = 0,r = n;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) ans = min(ans,mid),r = mid - 1;
        else l = mid + 1;
    }
    //找到第一个不满足条件的位置
    int x = m + 1;
    l = 1,r = m;
    while(l <= r){
        int mid = l + r >> 1;
        a[1] = mid;
        for(int i=2;i<=n;i++) a[i] = c[i];
        sort(a+1,a+1+n);
        if(!check(ans)){
            x = min(x,mid);
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans * (x-1) + (ans + 1) * (m - x + 1) << endl;
    
    //找到最后一个满足条件的位置
    // int x = 0;
    // l = 1,r = m;
    // while(l <= r){
    //     int mid = l + r >> 1;
    //     a[1] = mid;
    //     for(int i=2;i<=n;i++) a[i] = c[i];
    //     sort(a+1,a+1+n);
    //     // if(!check(ans)){
    //     //     x = min(x,mid);
    //     //     r = mid - 1;
    //     // }else l = mid + 1;
    //     if(check(ans)){
    //         x = max(x,mid);
    //         l = mid + 1;
    //     }else r = mid - 1;
    // }
    // cout << ans*x + (ans+1)*(m-x) << endl;

    //找到最后一个满足条件的位置
    // l = 1,r = m;
    // while(l < r){
    //     int mid = l + r + 1 >> 1;
    //     a[1] = mid;
    //     for(int i=2;i<=n;i++) a[i] = c[i];
    //     sort(a+1,a+1+n);
    //     if(check(ans)){
    //         l = mid;
    //     }else r = mid - 1;
    // }
    // cout << ans * l + (ans + 1) * (m - l) << endl;

    //找到第一个不满足条件的位置
    // l = 1,r = m + 1;
    // while(l < r){
    //     int mid = l + r >> 1;
    //     a[1] = mid;
    //     for(int i=2;i<=n;i++) a[i] = c[i];
    //     sort(a+1,a+1+n);
    //     if(!check(ans)){
    //         r = mid;
    //     }else l = mid + 1;
    // }
    // cout << ans * (l - 1) + (ans + 1) * (m - l + 1) << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}