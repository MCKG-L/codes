#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a){
        cin >> i;
    }
    sort(a.begin(),a.end());
    n = unique(a.begin(),a.end()) - a.begin();
    for(int i=0;i<n;i++){
        cout << a[i] << " \n"[i==n-1];
    }
    return 0;
}