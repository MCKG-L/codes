#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int p[N];
int n,m;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    while(m--){
        int z,x,y;
        cin >> z >> x >> y;
        if(z == 1) p[find(x)] = find(y);
        else{
            if(p[find(x)] == p[find(y)]) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
    return 0;
}