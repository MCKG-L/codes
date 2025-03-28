#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;
// vector<pair<int,string>> p(N);
pair<int,string> p[N];
int main()
{
    int n,m;cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;int x;
        cin >> x >> s;
        p[i] = {make_pair(x,s)};
    }
    int ans = 0;
    // for(int i=0;i<n;i++) cout << p[i].first << ' ' << p[i].second << endl;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        int k = p[ans].first == 0 ? 1 : -1;
        if(a == 0) k *= -1;
        ans = (ans + k*b + n) % n;
    }
    cout << p[ans].second << endl;
    return 0;
}