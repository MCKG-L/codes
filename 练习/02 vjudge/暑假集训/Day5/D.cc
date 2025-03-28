#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n;
/*
三个工匠可以同时处理所有人的toy
每个工匠可以选取一个恰当的初始x值，尽可能使自己负责的顾客的等待时间的最大值最小
将a排序可以分为三部分，分别交给三个工匠处理
*/
bool check(int x){
    int lst = a[1];
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(a[i]-lst>2*x){//满足不了最大等待时间 需要另外开一个工匠
            cnt ++;
            lst = a[i];
        }
        //最多有3个工匠
        if(cnt >= 3) return false;
    }
    return true;
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n <= 3){
        cout << 0 << endl;
        return;
    }
    sort(a+1,a+1+n);
    int l=0,r=1e9;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}