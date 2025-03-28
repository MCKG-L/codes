#include <iostream>
#include <unordered_map>
#define endl '\n'
using namespace std;
unordered_map<int,int> mp;//武器
int hp;//结构值
//超时！！！
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin >> n >> hp;
    while(n--){
        int op;cin >> op;
        if(op == 0){
            int x;cin >> x;
            mp[x]++;
        }
        else if(op == 1){
            int x;cin >> x;
            if(mp[x] == 1) mp.erase(x);
        }else if(op == 2){
            int x,h;
            cin >> x >> h;
            int cnt = 0;
            for(auto [s,t] : mp){
                if(t <= 0) continue;
                if((s ^ x) > h) cnt += t;
            }
            if(cnt == 0) hp --;
            cout << cnt << endl;
        }
    }
    cout << hp << endl;
    return 0;
}