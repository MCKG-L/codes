#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
char g[2][4];
unordered_map<string,int> dis;
unordered_map<string,pair<char,string>> pre;
queue<string> que;
void inhash(string s){
    for(int i=0;i<4;i++) g[0][i] = s[i];
    for(int i=3,j=4;i>=0;i--,j++) g[1][i] = s[j];
}
string Hash(){
    string s;
    for(int i=0;i<4;i++) s += g[0][i];
    for(int i=3;i>=0;i--) s += g[1][i];
    return s;
}
string move0(string s){
    inhash(s);
    for(int i=0;i<4;i++) swap(g[0][i],g[1][i]);
    
    return Hash();
}
string move1(string s){
    inhash(s);
    char a = g[0][3],b = g[1][3];
    for(int i=3;i>0;i--){
        for(int j=0;j<2;j++){
            g[j][i] = g[j][i-1];
        }
    }
    g[0][0] = a,g[1][0] = b;
    return Hash();
}
string move2(string s){
    inhash(s);
    char v = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = v;
    return Hash();
}
void bfs(string st,string ed){
    if(st == ed) return;
    que.push(st);
    dis[st] = 0;
    while(que.size()){
        string t = que.front();que.pop();
        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);
        for(int i=0;i<3;i++){
            string s = m[i];
            if(!dis.count(s)){
                dis[s] = dis[t] + 1;
                pre[s] = {(char)('A'+i),t};
                que.push(s);
                if(s == ed) break;
            }
        }
    }
}
int main()
{
    int x;
    string st,ed;
    for(int i=0;i<8;i++){
        cin >> x;
        ed += (char)(x + '0');
    }
    for(int i=0;i<8;i++) st += (char)(i + '1');
    bfs(st,ed);
    string ans;
    cout << dis[ed] << endl;
    while(ed != st){
        ans += pre[ed].first;
        ed = pre[ed].second;
    }
    reverse(ans.begin(),ans.end());
    if(ans.size() > 0){
        cout << ans << endl;
    }
    return 0;
}