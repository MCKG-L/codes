#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n,k;
    while(cin >> n >> k){
        vector<int> a(n);
        for(int &i : a){
            cin >> i;
        }
        for_each(a.begin(),a.end(),[&](int &x){cout << x << endl;});
        for_each(a.begin(),a.end(),[&](int &x){x += k;cout << x << endl;});
        cout << accumulate(a.begin(),a.end(),0) << endl;
    }
    return 0;
}