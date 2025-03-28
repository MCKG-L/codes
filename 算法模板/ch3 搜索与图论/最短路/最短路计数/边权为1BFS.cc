#include <iostream>
#include <cstring>
#include <queue>
#define mod 100003
using namespace std;
const int N = 1e6 + 10, M = 2e6 + 10;
int e[M], ne[M], h[N], idx;
int dis[N], cnt[N];
bool st[N];
int n, m;
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void bfs() {
    queue<int> q;
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;cnt[1] = 1;
    q.push(1);st[1] = 1;
    while (q.size()) {
        int t = q.front(); q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                cnt[j] = (cnt[j] + cnt[t]) % mod;
                q.push(j);
                dis[j] = dis[t] + 1;
                st[j] = true;
            }
            else {
                if (dis[t] + 1 == dis[j])
                    cnt[j] = (cnt[j] + cnt[t]) % mod;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << endl;
    }
    return 0;
}