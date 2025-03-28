#include <bits/stdc++.h>
using namespace std;
const int N1 = 6e6+5,N2 = 1e8+5;
int cnt;
int p[N1];//10^8内有5761455个素数，不超过6e6
bool st[N2];//不会超过125MB
//朴素筛 O(nlogn)
void getp_1(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) p[cnt++] = i;
        for(int j=i+i;j<=n;j+=i){
            st[j] = 1;
        }
    }
}

//埃式筛 O(nloglogn)
void getp_2(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]){
            p[cnt++] = i;
            for(int j=i+i;j<=n;j+=i){
                st[j] = 1;
            }
        }
    }
}

//线性筛 O(n)
void getp_3(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) p[cnt++] = i;
        for(int j=0;p[j]<=n/i;j++){//j<=cnt可以不加
            st[p[j]*i] = 1;
            if(i % p[j] == 0) break;//保证合数只被最小质因子划掉
        }
    }
}
//3.4 线性筛求欧拉函数
//i为质数：phi[i] = i - 1
//i % p[j] == 0: phi[p[j]*i] = p[j]*phi[i]
//i % p[j] != 0: phi[p[j]*i] = phi[i]*p[j]*(1-1/p[j]) = phi[i]*(p[j]-1)

int phi[N2];
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
    getp_2(n);
    get_eulers(n);
    // cout << cnt << '\n';
    for(int i=1;i<=n;i++){
        // cout << p[i] << " ";
        cout  << phi[i] << ' ';
    }
    return 0;
}