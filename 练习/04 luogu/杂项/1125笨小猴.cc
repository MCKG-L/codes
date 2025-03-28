#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int mask[125] = {};
    for(int i=0;i<s.size();i++){
        mask[s[i]]++; 
    }
    int maxn = 0,minn = 100;
    for(int i='a';i<='z';i++){
        if(mask[i] != 0){
            minn = min(mask[i],minn);
            maxn = max(mask[i],maxn);
        }
    }
    int x = maxn - minn;
    bool f = true;
    if(x <= 1) f = false;
    for(int i=2;i*i<=x;i++){
        if(x % i == 0){
            f = false;
            break;
        }
    }
    if(f) cout << "Lucky Word" << '\n' << x;
    else cout << "No Answer" << '\n' << 0;
}