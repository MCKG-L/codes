#include <bits/stdc++.h>
using namespace std;
int x,s,k = 1;
int a[11];
void dfs(int s,int t){
    for(int i=a[t-1];i<=s;i++){
        a[t] = i;
        s -= i;
        if(i == x)return;
        if(s == 0){
            for(int i=1;i<t;i++){
                cout << a[i] << "+";
            }
            cout << a[t] << endl;
        }else{
            dfs(s,t+1);
        }
        s += i;
    }
}
int main()
{
    cin >> x;
    a[0] = 1;
    dfs(x,1);
    return 0;
}