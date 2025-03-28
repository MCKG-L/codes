#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    while(cin >> n >> k){
        vector<int> a(n);
        for(int &i : a) cin >> i;
        auto it = adjacent_find(a.begin(),a.end(),[&](int &x,int &y){return fabs(x-y)<=k;});
        if(it == a.end()){
            cout << -1 << endl;
        }else{
            cout << it-a.begin() << ' ' << it-a.begin()+1 << endl;

        }
        return 0;
    }
}