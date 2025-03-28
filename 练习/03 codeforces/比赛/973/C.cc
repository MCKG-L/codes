#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
void solve(){
    int a,b;
    scanf("%02d:%02d",&a,&b);
    if(a >= 12){
        a -= 12;
        if(a == 0) a = 12;
        printf("%02d:%02d PM\n",a,b);
    }else{
        if(a == 0) a = 12;
        printf("%02d:%02d AM\n",a,b);
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --) solve();
    return 0;
}