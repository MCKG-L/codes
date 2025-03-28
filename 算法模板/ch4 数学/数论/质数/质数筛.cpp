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
            if(i % p[j] == 0) break;//保证p[j]是i的最小质因子，同时也是p[j]*i的最小质因子
        }
    }
}

//3.4 线性筛求欧拉函数
int phi[N2];
void get_eulers(int n) {
    for (int i = 2; i <= n; i ++) {
        if(!st[i]) {
            p[cnt ++] = i;
            phi[i] = i - 1;//质数的欧拉函数为p-1
        }
        for (int j = 0; p[j] <= n/i; j ++) {
            st[p[j] * i] = true;
            if (i % p[j] == 0) { //p[j]是i的质因子 
                phi[p[j] * i] = phi[i] * p[j]; //p[j]*i和i的质因子相同
                break;
            }
            //p[j]不是i的质因子 p[j]*i的质因子比i多一个p[j]
            //--> phi[p[j]*i] = p[j] * phi[i] * (1 - 1/p[j]) == ph[i] * (p[j] - 1)
            phi[p[j] * i] = (p[j] - 1) * phi[i];
        }
    }
}
int main()
{
    int n;cin >> n;
    getp_2(1e6);
    cout << cnt << '\n';
    for(int i=1;i<=n;i++){
        cout << st[i] << ' ';
    }
    cout << endl;
    // for(int i=0;i<cnt;i++){
    //     cout << p[i] << " ";
    // }
    return 0;
}
