#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10010;
int e[N],h[N],ne[N],idx;
int q[N],d[N];
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool topsort(){
    int hh = 0,tt = -1;
    for(int i=1;i<=n;i++){
        if(!d[i]) q[++ tt] = i;
    }
    while(hh <= tt){
        int t = q[hh++];
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            d[j]--;
            if(!d[j]) q[++tt] = j;
        }
    }
    return tt == n-1;
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        cin >> a >> b;
        add(a,b);
        d[b]++;
    }
    if(topsort()){
        for(int i=0;i<n;i++){
            cout << q[i] << ' ';
        }
        cout << endl;
    }
    else cout << "impossible!" << endl;
    return 0;
}