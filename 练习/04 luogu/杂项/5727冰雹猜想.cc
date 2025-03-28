#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    vector<int> a;
    a.push_back(n);
    while(n!=1){
        if(n % 2 == 0){
            n /= 2;
        }else{
            n = n * 3 + 1;
        }
        a.push_back(n);
    }
    for(int i=a.size()-1;i>=0;i--){
        cout << a[i] << " \0"[i == 0];
    }
    return 0;
}