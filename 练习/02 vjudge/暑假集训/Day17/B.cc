#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define endl '\n'
/*
超时！！！
*/
using namespace std;
typedef pair<int,int> PII;
const int N = 3e5 + 10;
vector<int> ans;
int n,k;
struct cmp{
    bool operator()(const PII &p1,const PII &p2)const{
        if(p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second;
    }
};
void solve(){
    ans.clear();
    priority_queue<PII,vector<PII>,cmp> heap;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        heap.push(make_pair(x,i));
    }
    while(heap.size()){
        auto [x,id] = heap.top();
        x -= k;heap.pop();
        if(x > 0){
            heap.push(make_pair(x,id));
        }else{
            ans.push_back(id);
        }
    }
    for(auto i : ans){
        cout << i << ' ';
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}