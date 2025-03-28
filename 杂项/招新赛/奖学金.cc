#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
struct p{
    int id;
    double s;
}a[N];
bool cmp(p p1,p p2){
    if(p1.s != p2.s) return p1.s > p2.s;
    else return p1.id < p2.id;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,idx,act,p;
    cin >> n >> idx >> act >> p;
    for(int i=0;i<n;i++){
        int id,m;
        cin >> id >> m;
        ll s=0,sw=0;//爆int
        for(int j=0;j<m;j++){
            int si,wi;
            cin >> wi >> si;
            s += si*wi;sw += wi;
        }
        double fs;
        if(id == idx){
            fs = s*1.0/sw*0.9+act*0.1;
        }
        else fs = s*1.0/sw*0.9;
        a[i].id = id;
        a[i].s = fs;
    }
    sort(a,a+n,cmp);
    int rank = 0;
    for(int i=0;i<n;i++){
        if(a[i].id == idx){
            rank = i + 1;
            break;
        }
    }
    int k = ceil(n*p/100.0);
    if(rank <= k) cout << "YES";
    else cout << "NO";
}