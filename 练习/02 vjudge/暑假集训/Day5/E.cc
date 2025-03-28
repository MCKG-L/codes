#include<bits/stdc++.h>
using namespace std;
int cnt;
string ss[3];
struct node {
    int x; int ti;
    bool operator<(struct node a)const {
        return ti< a.ti;
    }
};
multiset<node>s;
int main() {
    int qq; cin >> qq;
    while (qq--) {
        s.clear();
        cin >> ss[0] >> ss[1];
        int n = ss[0].size(); ss[0] = " " + ss[0]; ss[1] = " " + ss[1];
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (ss[0][i] != ss[1][i])cnt++;
        }
        int t, q; cin >> t >> q;
        for (int i = 1; i <= q; i++) {
            int d;
            cin >> d;
            while (s.size() && (*s.begin()).ti == i)
            {
                int now = (*s.begin()).x;
                if (ss[0][now] != ss[1][now])cnt++;
                s.erase(s.begin());
            }
            if (d == 1) {
                int pos; cin >> pos;
                if (ss[0][pos] != ss[1][pos])cnt--;
                s.insert({ pos,i + t });
            }
            else if (d == 2) {
                int x1, x2, pos1, pos2;
                cin >> x1 >> pos1 >> x2 >> pos2;
                x1--; x2--;
                if (ss[x1][pos1] != ss[x1 ^ 1][pos1])cnt--;
                if (ss[x1][pos2] != ss[x1 ^ 1][pos2])cnt--;
                swap(ss[x1][pos1], ss[x2][pos2]);
                if (ss[x1][pos1] != ss[x1 ^ 1][pos1])cnt++;
                if (ss[x1][pos2] != ss[x1 ^ 1][pos2])cnt++;
            }
            else {
                if (cnt == 0)cout << "YES\n";
                else cout << "NO\n";
            }
        }
    
    }
    
    return 0;
}
                                                                    