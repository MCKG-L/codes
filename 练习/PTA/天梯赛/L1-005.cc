#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1005;
struct p{
    string id;
    int a,b;
}s[N];
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i].id >> s[i].a >> s[i].b;
    }
    int m;cin >> m;
    sort(s,s+n,[&](p p1,p p2){return p1.a < p2.a;});
    while(m--){
        int x;cin >> x;
        cout << s[x-1].id << " " << s[x-1].b << endl;
    }
    return 0;
}