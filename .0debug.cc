#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1010;
int p[N];
int n,m,cnt;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
struct Node{
    int a,b,t;
};
vector<Node> v;
void merge(int a,int b){
    a = find(a),b = find(b);
    if(a != b){
        cnt --;
        p[a] = b;
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    while(m--){
        int a,b,t;
        cin >> a >> b >> t;
        v.push_back({a,b,t});
    }
    sort(v.begin(),v.end(),[&](Node p1,Node p2){return p1.t < p2.t;});
    cnt = n;
    bool mask = 0;
    for(int i=0;i<v.size();i++){
        int a = v[i].a,b = v[i].b,t = v[i].t;
        merge(a,b);
        if(cnt == 1){
            cout << t << endl;
            mask = 1;break;
        }
    }
    if(!mask){
        cout << -1 << endl;
    }
    return 0;
}