#include <iostream>
#include <map>
#include <cmath>
using namespace std;
int main()
{
    int id,h,m;char c,op;
    int n;cin >> n;
    while(n--){
        map<int,int> mp;
        int cnt=0,sum=0;
        while(1){
            cin >> id >> op >> h >> c >> m;
            if(id == 0) break;
            if(op == 'S'){
                //坑点2 ：以最后一次的结束数据为准
                //insert操作保留第一次出现的数据
                //mp.insert({id,h*60+m});
                mp[id] = h*60+m;
            }
            if(op == 'E' && mp.count(id)){
                sum += h*60+m-mp[id];
                mp.erase(id);cnt++;
            }
        }
        if(cnt == 0) cout << 0 << " " << 0 << endl;
        else{
            //坑点1 ：结果四舍五入
            // int ans = (int)(1.0*sum/cnt+0.5);
            int ans = round(1.0*sum/cnt);
            cout << cnt << " " << ans << endl;
        }
    }
    return 0;
}