#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int M = 1e4 + 5;
int h[N],e[M],ne[M],idx=0,w[M];
//头插法
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
/*
6 9
1 2
1 3
1 4
2 5
3 4
3 5
3 6
4 6
5 6
*/
int main()
{
    int n,m,a,b,v;
    memset(h,-1,sizeof(h));
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a >> b;
        add(a,b);
        add(b,a); //加上则为无向图，双向边
    }
    //输出
    for(int j=1;j<=n;j++){
        cout << "点" << j << "可以到的点有";
        for(int i=h[j];~i;i=ne[i]){
            cout << "-->点" << e[i];
        }
        cout << endl;
    }
    return 0;
}