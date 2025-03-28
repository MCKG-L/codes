#include <iostream>
#include <set>
#include <cstring>
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
set<PII> st;
char s[3][N];
void solve(){
    st.clear();
    int cnt = 0;
    cin >> s[1] + 1 >> s[2] + 1;
    int t,q;
    cin >> t >> q;
    for(int i=1;s[1][i];i++){
        if(s[1][i] != s[2][i]) cnt ++;
    }
    for(int i=1;i<=q;i++){
        int op;cin >> op;
        while(st.size()){
            if(st.begin()->first > i) break;
            PII p = *st.begin();
            if(s[1][p.second] != s[2][p.second]) cnt++;
            st.erase(st.begin());
        }
        if(op == 1){
            int pos;cin >> pos;
            if(s[1][pos] != s[2][pos]) cnt--;
            st.insert(make_pair(i+t,pos));
        }else if(op == 2){
            int s1,s2,p1,p2;
            cin >> s1 >> p1 >> s2 >> p2;
            if(s[s1][p1] != s[3-s1][p1]) cnt--;
            if(s[s2][p2] != s[3-s2][p2]) cnt--;
            swap(s[s1][p1],s[s2][p2]);
            if(s[s1][p1] != s[3-s1][p1]) cnt++;
            if(s[s2][p2] != s[3-s2][p2]) cnt++;
        }else if(op == 3){
            if(cnt == 0) puts("YES");
            else puts("NO");
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}