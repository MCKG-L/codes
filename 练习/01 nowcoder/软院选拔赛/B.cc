#include <iostream>
#include <cstring>
using namespace std;
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
    for(int i=0;i<s.size();i++){
        for(int j=1;j<s.size()-i+1;j++){
            string t = s.substr(i,j);
            // cout << t << ' ';
            if(!func(t,r)) break;
            if(func(l,t)&&func(t,r)) ans++;
        }
    }
    // cout << ans << endl;
    return 0;
}