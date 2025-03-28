#include <bits/stdc++.h>
using namespace std;
int main()
{
    double s;cin >> s;
    double sum = 0,ans = 1,cur = 2;
    sum += cur;
    while(sum < s){
        cur *= 0.98;
        sum += cur;
        ans++;
    }
    cout << ans;
    return 0;
}