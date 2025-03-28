#include <bits/stdc++.h>
using namespace std;
int p,s,t;
int main()
{
    int a,b,c;
    char ch;
    cin >> a >> ch >> b >> ch >> c;
    p = a * 3600 + b * 60 + c;
    cin >> a >> ch >> b >> ch >> c;
    s = a * 3600 + b * 60 + c;
    cin >> a >> ch >> b >> ch >> c;
    t = a * 3600 + b * 60 + c;
    bool mask = false;
    int ans = 0;
    for(int i=1;i<=24*3600&&i*t<=24*3600;i++){
        p += t;
        p %= 24 * 3600;
        if(p == s){
            mask = true;
            ans = i;
            break;
        }
    }
    if(mask){
        cout << ans;
    }else{
        cout << -1;
    }
    return 0;
}