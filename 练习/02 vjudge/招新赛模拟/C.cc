#include <iostream>
#include <cstring>
using namespace std;
const int N = 3e5 + 10;
int n,k;
int a[N],p[N];
void solve(){
    memset(a,0x3f,sizeof a);
    cin >> n >> k;
    for(int i=0;i<k;i++) cin >> p[i];
    for(int i=0;i<k;i++){
        int t;cin >> t;
        a[p[i]] = t;
    }

    //某一个位置的温度，受其左边或者右边相邻的位置影响
    //正向递推
    for(int i=2;i<=n;i++){
        a[i] = min(a[i],a[i-1]+1);
    }
    //反向递推
    for(int i=n-1;i>=1;i--){
        a[i] = min(a[i],a[i+1]+1);
    }
    for(int i=1;i<=n;i++) cout << a[i] << ' ';
    cout << endl;

}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}