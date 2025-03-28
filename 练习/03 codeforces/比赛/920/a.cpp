#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve(){
    int h,w,x1,x2,y1,y2;
    cin >> h >> w >> x1 >> y1 >> x2 >> y2;
    string ans[3] = {"Draw","Alice","Bob"};
    if(x1 > x2){
        cout << ans[0] << endl;
    }else{
        if((x2 - x1) & 0x1){
            int t = abs(x2-x1) / 2;
            if(y1 < y2){
                if(t - min(t,w-y2) + 1 >= y2 - y1){
                    cout << ans[1] << endl;
                }else{
                    cout << ans[0] << endl;
                }
            }else{
                if(t - min(t,y2-1) + 1 >= y1 - y2){
                    cout << ans[1] << endl;
                }else{
                    cout << ans[0] << endl;
                }
            }
        }else{
            int t = abs(x1-x2) / 2;
            if(y1 < y2){
                if(t - min(t,y1-1) >= y2 - y1){
                    cout << ans[2] << endl;
                }else{
                    cout << ans[0] << endl;
                }
            }else{
                if(t - min(t,w-y1) >= y1 - y2){
                    cout << ans[2] << endl;
                }else{
                    cout << ans[0] << endl;
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}