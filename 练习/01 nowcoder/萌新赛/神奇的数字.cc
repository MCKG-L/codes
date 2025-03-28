#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int t;cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == b && b == c){
            cout << -1 << " ";
            continue;
        }
        int g = __gcd(abs(a-b),abs(b-c));
        //找g的因子
        vector<int> ans;
        for(int i=1;i<=g/i;i++){
            if(g % i == 0){
                ans.push_back(i);
                if(i != g/i) ans.push_back(g/i);
            }
        }
        sort(ans.begin(),ans.end());
        for(auto it : ans){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}