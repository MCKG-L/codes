#include <bits/stdc++.h>
using namespace std;
int a[100];
bool b[100],c[100],d[100];
int cnt,n;
void print(){
    if(cnt < 3)
        for(int k=1;k<=n;k++)
            cout << a[k] << " \n"[k == n];
    cnt ++;
}
void dfs(int i){
    if(i > n){
        print();
        return;
    }
    for(int j=1;j<=n;j++){
        if(!b[j]&&!c[i+j]&&!d[i-j+n]){
            //标记
            a[i] = j;//行
            b[j] = 1;//列
            c[i+j] = 1;//主对角线
            d[i-j+n] = 1;//副对角线
            //下一个皇后
            dfs(i+1);
            //回溯 清除标记
            b[j] = 0;
            c[i+j] = 0;
            d[i-j+n] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << cnt;
    return 0;
}