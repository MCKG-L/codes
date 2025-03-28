#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
bool func(string s,string p){
    if(s.size() != p.size()){
        return s.size() < p.size();
    }
    return s <= p;
}
int main()
{
    string s,l,r;
    cin >> l >> r >> s;
    long long ans = 0;
    int cnt = 1;
    for(int i=0;i<s.size();i++){
        if(s[i] == '0'){
            cnt++;
            continue;
        }
        for(int j=1;j <= 26 && j<s.size()-i+1;j++){
            string t = s.substr(i,j);
//             if(!func(t,r)) break;
            if(func(l,t)&&func(t,r)) ans+=cnt;
        }
        cnt = 1;
    }
    cout << ans << endl;
    return 0;
}