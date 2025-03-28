#include <bits/stdc++.h>
using namespace std;
const int N = 6e6,M = 1e9+10;
int pr[N];
bool vis[M];
int cnt;
// void get_Prime(int n){
//     for(int i=2;i<=n;i++){
//         if(!vis[i]){
//             pr[cnt++] = i;
//         }
//         for(int j=0;pr[j]<=n/i;j++){
//             vis[pr[j]*i] = 1;
//             if(i % pr[j] == 0) break;
//         }
//     }
// }
void get_Prime(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            pr[cnt++] = i;
        }
        for(int j=0;pr[j]<=n/i;j++){
            vis[pr[j]*i] = 1;
            if(i % pr[j] == 0) break;
        }
    }
}
int main()
{
    int n;cin >> n;
    get_Prime(n);
    for(int i=0;i<cnt;i++){
        cout << pr[i] << " ";
    }
    return 0;
}