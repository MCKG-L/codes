#include <iostream>
#include <map>
using namespace std;
const int N = 1e9 + 10;
int a[N];
map<int,int> mp1,mp2;
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        char c;cin >> c;
        if(c == 'B') mp1[a[i]] ++;
        else mp2[a[i]] ++;
    }
    int ans = 0;
    for(auto i : mp1){
        ans += mp2[i.first];
    }
    cout << ans << endl;
    return 0;
}