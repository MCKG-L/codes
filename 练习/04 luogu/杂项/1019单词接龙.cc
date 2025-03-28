#include <bits/stdc++.h>
using namespace std;
const int N = 25;
string words[N];
int dd[N][N];
int vis[N];
int ans = -1,n,s;
//求最小重叠部分
int find(int x,int y){
    for(int k=words[x].size()-1;k>=0;k--){
        int ky = 0;
        bool mask = true;
        for(int kx=k;kx<words[x].size();kx++){
            if(words[x][kx]!=words[y][ky++]){
                mask = false;
                break;
            }
        }
        if(mask){
            return words[x].size()-k;
        }
    }
    return 0;
}
void dfs(int x){//x已经接上，作为尾部
    bool mask = false;
    for(int i=0;i<n;i++){
        if(dd[x][i] == 0) continue;
        if(vis[i] >= 2) continue;
        //存在包含关系
        if(dd[x][i] == words[x].size() || dd[x][i] == words[i].size()){
            continue;
        }
        //可以接上
        mask = true;
        vis[i]++;
        s += words[i].size() - dd[x][i];
        dfs(i);
        //回溯
        s -= words[i].size() - dd[x][i];
        vis[i]--;
    }
    if(!mask) ans = max(ans,s);
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> words[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dd[i][j] = find(i,j);
        }
    }
    char ch;
    cin >> ch;
    for(int i=0;i<n;i++){
        if(words[i][0] == ch){
            vis[i]++;
            s = words[i].size();
            dfs(i);
            s = 0;
            vis[i] = 0;
        }
    }
    cout << ans;
}