#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    int maxn = max(a,max(b,c));
    int minn = min(a,min(b,c));
    int mid = a + b + c - maxn - minn;
    for(int i=0;i<3;i++){
        char c;
        cin >> c;//cin默认不读取空白符，并处理掉
        if(c == 'A') cout << minn;
        else if(c == 'B') cout << mid;
        else if(c == 'C') cout << maxn;
        cout << " \0"[i==2];
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //solve();
    int a,b;
    char c;
    cin >> a >> b >> c;
    cout << c;
    return 0;
}