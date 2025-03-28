#include <iostream>
#include <vector>
using namespace std;
const int N = 1010;
int n;
int a[N],f[N];
void solve(){

}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    // for(int i=1;i<=n;i++){
    //     f[i] = 1;
    //     for(int j=1;j<i;j++){
    //         if(a[j] < a[i]){
    //             f[i] = max(f[i],f[j]+1);
    //         }
    //     }
    // }
    // int ans = 0;
    // for(int i=1;i<=n;i++) ans = max(ans,f[i]);
    // cout << ans << endl;

    //贪心+二分 nlog(n)求LIS
    vector<int> s(n + 1);
    int len = 0;
    s[0] = -1e9;
    for(int i=1;i<=n;i++){
        int x = a[i];
        int l = 0,r = len;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(s[mid] < x) l = mid + 1;
            else r = mid - 1;
        }
        len = max(len,r+1);
        s[r+1] = x;
    }
    cout << len << endl;

    return 0;
}