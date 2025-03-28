// #include <algorithm>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a){
        cin >> i;
    }
    for(auto i=a.begin();i!=a.end();i++){
        cout << *i << " \n"[i == prev(a.end())];
    }
    return 0;
}