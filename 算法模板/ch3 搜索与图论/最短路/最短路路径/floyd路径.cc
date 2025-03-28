#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
6 8 0
1 2 5
1 3 1
2 3 8
2 4 7
3 4 3
3 6 7
4 5 1
5 6 1
*/
const int N = 210,INF = 1e9;
int n,m,q;
int d[N][N];
int path[N][N];
//path[i][j]存储的是从i到j的最短路所经过的最后一个中间结点
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}
void print(int i,int j){
    //输出从i到j的最短路路径
    if(i == j) return;
    if(!path[i][j]) cout << i << "->";
    else{
        print(i,path[i][j]);
        print(path[i][j],j);
    }
}

int main()
{
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) d[i][j] = 0;//处理自环的情况
            else d[i][j] = INF;
        }
    }
    while(m--){
        int a,b,w;
        cin >> a >> b >> w;
        d[a][b] = min(d[a][b],w);//处理重边的情况
        d[b][a] = min(d[b][a],w);
    }
    floyd();//不要忘了
    //最短路矩阵
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
    //path矩阵
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << path[i][j] << ' ';
        }
        cout << endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            cout << "从"<< i << "到" << j << "的最短路长度为" << d[i][j] << endl;
            cout << "路径为：";
            print(i,j);
            cout << j << endl;
        }
    }
    cout << "路径：\n";
    print(1,6);
    while(q--){
        int a,b;
        cin >> a >> b;
        if(d[a][b] > INF / 2) cout << "impossible" << endl;
        //到不了的边不一定为INF，可能前面的边有负权
        else cout << d[a][b] << endl;
    }
    return 0;
}