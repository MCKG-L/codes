#include <iostream>
using namespace std;
int n;
int cnt;
const int N = 1e6,M = 1e8;
bool vis[M];
int pr[N];
void getprime(){
    int i = 2;
    while(1){
        if(!vis[i]) pr[cnt++] = i;
        for(int j=0;pr[j]<=n/i;j++){
            vis[pr[j]*i] = 1;
            if(i % pr[j] == 0) break;
        }
        if(cnt == n) break;
        i++;
    }

}
int main()
{
    cin >> n;
    getprime();
    for(int i=0;i<cnt;i++){
        cout << pr[i] << " ";
    }
    return 0;
}