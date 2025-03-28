#include <iostream>
using namespace std;
const int N = 1e8+10,M = 6e6;
int pr[M];
bool vis[N];
int cnt;
void get_primes(){
    for(int i=2;i<=N;i++){
        if(!vis[i]) pr[cnt++] = i;
        for(int j=0;pr[j]<=N/i;j++){
            vis[pr[j]*i] = 1;
            if(i % pr[j] == 0) break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    get_primes();
    cin >> n >> m;
    while(m--){
        int x;cin >> x;
        cout << pr[x-1] << '\n';
    }
    return 0;
}