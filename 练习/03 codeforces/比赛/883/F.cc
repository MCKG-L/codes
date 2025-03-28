#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
//交互式题目
void solve(){
    vector<int> a;
    map<int,int> mp;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a.push_back(x);
        mp[x] ++;
    }
    int ans = 0;
    vector<int> p;
    for(int _=0;_<5;_++){
        if(a.size() - p.size() == 1){
            cout << "! " << ans << endl;
            break;
        }
        cout << "- " << p.size() << ' ';
        for(auto i : p) cout << i << ' ';
        cout << endl;
        vector<int> b;
        map<int,int> mmp;
        int k = a.size() - p.size();
        for(int i=0;i<k;i++){
            int x;cin >> x;
            b.push_back(x);
            mmp[x] ++;
        }
        int type = -1;
        for(auto [x,y] : mmp){
            if(y > mp[x]){
                type = x;
            }
        }
        p.clear();
        if(type != -1){
            //说明伪装者改变了姿态 -删除所有其他种类的物体
            for(int i=0;i<b.size();i++){
                if(b[i] != type) p.push_back(i+1);
                else ans = i + 1;
            }
            mp.clear();
            mp[type] = mmp[type];
        }
        a = b;
    }
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}