#include <iostream>
using namespace std;
const int N = 1e8 + 10,M = 1e6;
bool vis[N];
int p[M];
int cnt;
void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            p[cnt++] = i;
        }
        for(int j=0;p[j]<=n/i;j++){
            vis[p[j]*i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt;
    return 0;
}