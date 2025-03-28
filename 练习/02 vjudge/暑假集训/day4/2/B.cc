#include <iostream>
using namespace std;
int main()
{
    int t;cin >> t;
    while(t--){
        int x = 0,y = 0;
        int n;cin >> n;
        string s;cin >> s;
        bool f = 0;
        for(auto i : s){
            if(i == 'U') y ++;
            if(i == 'R') x ++;
            if(i == 'L') x --;
            if(i == 'D') y --;
            if(x == 1 && y == 1){
                f = 1;break;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}