#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define endl '\n'
using namespace std;
struct Node{
    int id,s,f;
    bool operator<(const struct Node &node) const{
        return f < node.f;
    }
};
void solve2(){
    int n;cin >> n;
    vector<Node> p(n);
    for(int i=0;i<n;i++){
        int id,s,f;
        cin >> id >> s >> f;
        p[i] =  {id,s,f};
    }
    sort(p.begin(),p.end());
    int ed = -1;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(p[i].s >= ed){
            ans.push_back(p[i].id);
            ed = p[i].f;
        }
    }
    for(auto x : ans) cout << x << ' ';
    cout << endl;
}
void solve(){
    int n;cin >> n;
    vector<array<int,3>> p(n);
    for(int i=0;i<n;i++){
        int id,s,f;
        cin >> id >> s >> f;
        p[i] = {id,s,f};
    }
    sort(p.begin(),p.end(),[&](array<int,3> &A,array<int,3> &B){
        return A[2] < B[2];
    });
    int ed = -1;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(p[i][1] >= ed){
            ans.push_back(p[i][0]);
            ed = p[i][2];
        }
    }
    for(auto x : ans) cout << x << ' ';
    cout << endl;
}

int main()
{
    int T = 1;
    // cin >> T;
    while(T --) solve2();
    return 0;
}