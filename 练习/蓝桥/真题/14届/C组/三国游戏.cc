#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int a[N],b[N],c[N];
int n;
int find(int a[],int b[],int c[]){
    vector<int> p(n);
    for(int i=0;i<n;i++) p[i] = a[i] - b[i] - c[i];
    sort(p.begin(),p.end(),greater<int>());
    int sum = 0ll;
    for(int i=0;i<n;i++){
        sum += p[i];
        if(sum <= 0) return i;
    }
    return n;
}
signed main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];
    int res = max({find(a,b,c),find(b,a,c),find(c,a,b)});
    if(res == 0) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}