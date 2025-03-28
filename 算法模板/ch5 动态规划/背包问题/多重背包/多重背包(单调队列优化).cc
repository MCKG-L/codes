#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, M = 20010;

int n, m;
int v[N], w[N], s[N];
int f[M], g[M];
int q[M];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; ++ i)
    {
        memcpy(g, f, sizeof g);
        for (int r = 0; r < v[i]; ++ r)
        {
            int hh = 0, tt = -1;
            for (int j = r; j <= m; j += v[i])
            {
                while (hh <= tt && j - q[hh] > s[i] * v[i]) hh ++ ;
                while (hh <= tt && g[q[tt]] + (j - q[tt]) / v[i] * w[i] <= g[j]) -- tt;
                q[ ++ tt] = j;
                f[j] = g[q[hh]] + (j - q[hh]) / v[i] * w[i];
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}