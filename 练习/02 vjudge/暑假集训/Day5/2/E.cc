#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char s[2][N];
int t,q;
void solve(){
    set<pair<int,int>> st;
    cin >> s[0] + 1 >> s[1] + 1;
    cin >> t >> q;
    int cnt = 0;
    for(int i=1;s[0][i];i++){
        if(s[0][i] != s[1][i]) cnt ++;
    }
    for(int i=1;i<=q;i++){
        while(st.size()){
            pair<int,int> p = *st.begin();
            if(p.first > i) break;
            if(s[0][p.second] != s[1][p.second]) cnt ++;
            st.erase(st.begin());
        }
        int op;cin >> op;
        if(op == 1){
            int pos;cin >> pos;
            st.insert(make_pair(i+t,pos));
            if(s[0][pos] != s[1][pos]) cnt --;
        }else if(op == 2){
            int s1,s2,p1,p2;
            cin >> s1 >> p1 >> s2 >> p2;
            s1 --,s2 --;
            if(s[s1][p1] != s[s1^1][p1]) cnt --;
            if(s[s2][p2] != s[s2^1][p2]) cnt --;
            swap(s[s1][p1],s[s2][p2]);
            if(s[s1][p1] != s[s1^1][p1]) cnt ++;
            if(s[s2][p2] != s[s2^1][p2]) cnt ++;
        }else{
            cout << (cnt ? "NO" : "YES") << endl;
        }
    }
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}