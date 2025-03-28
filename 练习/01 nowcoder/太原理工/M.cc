#include <iostream>
#include <map>
using namespace std;
map<int,int> mp;
int main()
{
    int n;cin >> n;
    long long ans = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        ans += i - mp[x];
        mp[x] ++;
    }
    cout << ans << endl;
    return 0;
}