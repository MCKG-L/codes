#include <iostream>
#include <cstring>
using namespace std;
const int N = 4e5 + 10;
int id, h[N], e[N], nex[N],res[N],bk[N];
int p[N];
bool broken[N];
int n, m, k, ans;
void add(int a, int b) {
    e[id] = b;
    nex[id] = h[a];
    h[a] = id++;
}
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
        p[a] = b;
        ans--;
    }
}

int main()
{

    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        add(x, y), add(y, x);
    }
    cin >> k;
    //int bk[k];
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        broken[x] = 1;
        bk[i] = x;
    }
    ans = n - k;
    //for (int i = 0; i < 2 * m; i++) {
    //    int x = i, y = e[h[i]];
    //    if (!broken[x] && !broken[y]) {
    //        unite(x, y);
    //    }
    //}
    
     for(int j=0;j<n;j++){
     	for(int i=h[j];i!=-1;i=nex[i]){
     		int x = j,y = e[i];
     		if(!broken[x] && !broken[y]) unite(x,y);
     	}
     }
    //  cout << find(0) << ' ' << find(2) << ' ' << find(4) << '\n';
    // cout << ans << "-----\n";
    //int res[k + 1];
    res[k] = ans;
    for (int i = k - 1; i >= 0; i--) {
        int x = bk[i]; broken[x] = 0;
        ans++;
        for (int j = h[x]; j != -1; j = nex[j]) {
            int a = x, b = e[j];
            if (!broken[b]) {
                unite(a, b);
            }
        }
        // cout << ans << endl;
        res[i] = ans;
    }
    for (int i = 0; i <= k; i++) cout << res[i] << '\n';
    return 0;
}