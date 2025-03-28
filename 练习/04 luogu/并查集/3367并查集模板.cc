#include <iostream>
const int N = 1e4+10;
using namespace std;
int n,m;
int p[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    if(find(a) != find(b)){
        p[find(a)] = find(b);
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        p[i] = i;
    }
    while(m--){
        int z,a,b;
        cin >> z >> a >> b;
        if(z == 1) merge(a,b);
        else if(z == 2){
            if(find(a) == find(b)) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
    return 0;
}