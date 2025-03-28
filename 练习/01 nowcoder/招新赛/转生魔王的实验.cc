#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
ll qmi(ll a,ll b,ll p){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
int main()
{
    int t;cin >> t;
    while(t--){
        ll n,p;
        cin >> n >> p;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        if(p > 1){
	        sort(a.begin(),a.end());
	        long long max_n = qmi(p,a.back(),mod);
            long long an = 0;
	        for(int i=0;i<n-1;i++){
                an += qmi(p,a[i],mod);
                an %= mod;
        	}
            cout << ((max_n - an)%mod + mod)%mod << endl;
		}
		else{
			cout << (n & 1) << endl;
		}
    }
    return 0;
}