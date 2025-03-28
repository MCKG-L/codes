#include <iostream>
using namespace std;
const int N = 1e8 + 10;
int pr[(int)(N/100)*6];
bool vis[N];
int cnt;
void getprimes(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]) pr[cnt++] = i;
        for(int j=0;pr[j]<=n/i;j++){
            vis[pr[j]*i] = 1;
            if(i % pr[j] == 0) break;
        }
    }
}
int main()
{
    int n;cin >> n;
    getprimes(n);
    cout << cnt;
}