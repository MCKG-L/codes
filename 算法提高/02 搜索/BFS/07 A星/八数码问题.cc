#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;
//八数码问题存在解的充要条件是：对应串的逆序对数为偶数
/*
简单证明：可以发现每一次操作对串的逆序对数量的影响数一定是个偶数
所以从初始状态到目标状态，经过一定的操作后，串的逆序对数的奇偶性不变
而最终状态的逆序对数为0，所以初始状态有解当且仅当初始状态的逆序对数为偶数
*/
typedef pair<int,string> PIS;
string ed = "12345678x";
int f(string s){
    int res = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'x') continue;
        int t = s[i] - '1';
        res += abs(i/3-t/3) + abs(i%3-t%3);
    }
    return res;
}
string bfs(string st){
    char op[] = "urdl";
    unordered_map<string,int> dis;
    unordered_map<string,pair<char,string>> pre;
    priority_queue<PIS,vector<PIS>,greater<PIS>> heap;
    dis[st] = 0;
    heap.push({f(st),st});
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    while(heap.size()){
        PIS t = heap.top();heap.pop();
        string s = t.second;
        if(s == ed) break;
        int x,y;
        for(int i=0;i<9;i++){
            if(s[i] == 'x'){
                x = i / 3,y = i % 3;
                break;
            }
        }
        string init = s;
        for(int i=0;i<4;i++){
            int nx = x + dx[i],ny = y + dy[i];
            if(nx <0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            s = init;
            swap(s[x*3+y],s[nx*3+ny]);
            if(!dis.count(s) || dis[s] > dis[init] + 1){
                dis[s] = dis[init] + 1;
                pre[s] = make_pair(op[i],init);
                heap.push({f(s)+dis[s],s});
            }
        }
    }
    string res;
    while(ed != st){
        res += pre[ed].first;
        ed = pre[ed].second;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    string st,seq;
    char c;
    while(cin >> c){
        st += c;
        if(c != 'x') seq += c;
    }
    int cnt = 0;
    for(int i=0;i<8;i++){
        for(int j=i;j<8;j++){
            if(seq[i] > seq[j]) cnt ++;
        }
    }
    if(cnt & 1) cout << "unsolvable" << endl;
    else cout << bfs(st) << endl;
    return 0;
}