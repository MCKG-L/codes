#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
map<ll,ll> mp;
map<ll,ll> st;
vector<ll> ans;
void divide(ll n){
    for(int i=2;i<=n/i;i++){
        if(n % i == 0){
            while(n % i == 0){
                mp[i] ++;n /= i;
            }
        }
    }
    if(n) mp[n] ++;
}
int main()
{
    ll a,b;
    cin >> a >> b;
    divide(a);
    divide(b);
    ll cnt = 1,s = 1;
    for(auto i : mp){
        cnt *= (i.second + 1);
    }
    ans.push_back(1);
    for(auto p : mp){
        ll x = p.first,c = p.second;
        int n = ans.size();
        while(c--){
            for(int i=0;i<n;i++){
                if(!st.count(ans[i]*x)) ans.push_back(ans[i]*x);
                st[ans[i]*x] ++;
            }
            n = ans.size();
        }
    }
    sort(ans.begin(),ans.end());
    for(auto i : ans){
        cout << i << ' ';
    }
    return 0;
}