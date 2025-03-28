#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    int dx = 0,dy = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        dx += x,dy += y;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        cout << x + dx << ' ' << y + dy << endl;
    }
    return 0;
}