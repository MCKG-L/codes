#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1000010;
int p[N],cnt;
int phi[N];
bool st[N];
//时间复杂度：O(N)
//i为质数：phi[i] = i - 1
//i % p[j] == 0: phi[p[j]*i] = p[j]*phi[i]
//i % p[j] != 0: phi[p[j]*i] = phi[i]*p[j]*(1-1/p[j]) = phi[i]*(p[j]-1)
void get_eulers(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i ++) {
        if(!st[i]) {
            p[cnt ++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; p[j] <= n/i; j ++) {
            st[p[j] * i] = true;
            if (i % p[j] == 0) {
                phi[p[j] * i] = phi[i] * p[j];
                break;
            }
            phi[p[j] * i] = (p[j] - 1) * phi[i];
        }
    }
}
int main()
{
    int n;cin >> n;
    get_eulers(n);
    for(int i=1;i<=n;i++){
        cout << phi[i] << ' ';
    }
    return 0;
}