#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n){
        vector<int> a(n);
        for(int &i : a) cin >> i;
        auto it = adjacent_find(a.begin(),a.end());
        if(it == a.end()){
            cout << -1 << endl;
        }else{
            cout << it-a.begin() << ' ' << it-a.begin()+1 << endl;
        }
    }
    return 0;
}