#include <iostream>
using namespace std;
int n;
bool vis[10];
int ans[10];
//按照字典序进行全排列
// void dfs(int x){
//     if(x == n){
//         for(int i=0;i<n;i++) cout << ans[i] << ' ';
//         cout << endl;
//         return;
//     }
//     for(int i=1;i<=n;i++){
//         if(vis[i]==1) continue;
//         vis[i] = 1;
//         ans[x] = i;
//         dfs(x+1);
//         //回溯
//         vis[i] = 0;
//     }
// }
void dfs2(int x){
    if(x == n){
        for(int i=0;i<n;i++) cout << ans[i] << ' ';
        cout << endl;
        return;
    }
    for(int i=n;i>0;i--){
        if(vis[i]) continue;
        vis[i] = 1;
        ans[x] = i;
        dfs2(x + 1);
        vis[i] = 0;
    }

}
void dfs(int x){
    if(x == n){
        for(int i=0;i<n;i++) cout << ans[i] << ' ';
        cout << endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i] = 1;
        ans[x] = i;
        dfs(x + 1);
        //回溯
        vis[i] = 0;
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}