#include <iostream>
#include <cstring>
using namespace std;
const int N = 10;
int n;
struct Node{
    int t,d,l;
}p[N];
bool st[N];
bool dfs(int u,int k){
    if(u == n) return true;
    for(int i=0;i<n;i++){
        int t = p[i].t,d = p[i].d,l = p[i].l;
        if(!st[i] && t + d >= k){
            st[i] = true;
            if(dfs(u+1,max(t,k)+l)) return true;
            st[i] = false;
        }
    }
    return false;
}
int main()
{
    int T;cin >> T;
    while(T--){
        cin >> n;
        for(int i=0;i<n;i++){
            int t,d,l;
            cin >> t >> d >> l;
            p[i] = {t,d,l};
        }
        memset(st,false,sizeof st);
        if(dfs(0,0))puts("YES");
        else puts("NO");
    }
    return 0;
}