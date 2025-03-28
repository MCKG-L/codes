#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int p[N];
int w[N];
ll sum[N];
int n,q,k;
vector<int> h;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> q >> k;
    for(int i=1;i<=n;i++){
        cin >> w[i];
        sum[i] = sum[i-1] + w[i];
    }
    h.push_back(0);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        h.push_back(x);
    }
    for(int i=1;i<=n;i++){
        int l = max(1,i-k+1);
        p[i] = l;
        if(h[l] < h[i]){
            int it = lower_bound(h.begin(),h.end(),h[i])-h.begin();
            p[i] = p[it-1];
        }
    }
    while(q--){
        int x;cin >> x;
        cout << sum[x] - sum[p[x]-1] << endl;
    }
    return 0;
}