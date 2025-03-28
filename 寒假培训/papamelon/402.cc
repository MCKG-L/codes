#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin >> n){
        vector<int> a(n);
        for(int &i : a){
            cin >> i;
        }
        cin >> m;
        cout << count(a.begin(),a.end(),m);
    }
    return 0;
}