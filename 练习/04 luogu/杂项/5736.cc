#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N];
bool st[N];
int a[N],n,cnt;
void getPrimes(int n){
    st[1] = 1;
    for(int i=2;i<=n;i++){
        if(!st[i]) p[cnt++] = i;
        for(int j=0;p[j]<=n/i;j++){
            st[p[j]*i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    getPrimes(2 * n);
    for(int i=0;i<n;i++){
        if(st[a[i]]) continue;
        cout << a[i] << ' ';
    }
    return 0;
}