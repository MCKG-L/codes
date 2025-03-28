#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;cin >> n;
    int minn = 1000,maxn = 0;
    for(int i=0;i<n;i++){
        cin >> x;
        minn = min(minn,x);
        maxn = max(maxn,x);
    }
    cout << maxn - minn;
    return 0;
}