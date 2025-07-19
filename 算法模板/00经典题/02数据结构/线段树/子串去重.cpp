#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;
struct Node{
    string s;
}tr[N<<2];
bool book[26];
Node pushup(Node &ls,Node &rs){
    Node res;
    string s1 = ls.s,s2 = rs.s;
    res.s = s1;
    for(auto c : s1) book[c-'a'] = 1;
    for(auto c : s2){
        if(book[c-'a']) continue;
        book[c-'a'] = 1;
        res.s += c;
    }
    for(int i=0;i<26;i++) book[i] = 0;
    return res;
}
void pushup(int u){
    tr[u] = pushup(tr[u<<1],tr[u<<1|1]);
}
void modify(int u,int st,int ed,int pos,string v){
    if(st == ed){
        tr[u].s = v;
        return;
    }
    int mid = (st + ed) / 2;
    if(pos <= mid){
        modify(u<<1,st,mid,pos,v);
    }else{
        modify(u<<1|1,mid+1,ed,pos,v);
    }
    pushup(u);
}
Node ask(int u,int st,int ed,int l,int r){
    if(l <= st && ed <= r){
        return tr[u];
    }
    int mid =(st + ed) / 2;
    if(l > mid){
        return ask(u<<1|1,mid+1,ed,l,r);
    }else if(r <= mid){
        return ask(u<<1,st,mid,l,r);
    }else{
        Node res;
        Node ls = ask(u<<1,st,mid,l,r);
        Node rs = ask(u<<1|1,mid+1,ed,l,r);
        res = pushup(ls,rs);
        return res;
    }
}
void solve(){
    string s;cin >> s;
    int n = s.size();
    s = ' ' + s;
    for(int i=1;i<=n;i++){
        modify(1,1,n,i,s.substr(i,1));
    }
    int m;cin >> m;
    while(m --){
        int l1,l2,r1,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        Node ls = ask(1,1,n,l1,r1);
        Node rs = ask(1,1,n,l2,r2);
        string s1 = ls.s,s2 = rs.s;
        int n1 = s1.size(),n2 = s2.size();
        int ans = 0;
        for(int i=0;i<min(n1,n2);i++){
            if(s1[i] != s2[i]) ans ++;
        }
        ans += abs(n1-n2);
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}