#include <bits/stdc++.h>
using namespace std;
bool check(int num){
    int ans = 0,temp = num;
    while(temp!=0){
        ans = ans * 10 + temp % 10;
        temp /= 10;
    }
    if(ans == num) return 1;
    else return 0;
}
//线性筛 O(n)
// const int N = 1e8+5,N2 = 1e7;
// int st[N],p[N2];
//125MB内存不足 2^20*125/4 == 32768000
const int N = 1e8 + 5;//2^20*125
bool st[N];
int cnt;
//埃式筛 O(nloglogn)
void getprimes_3(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]){
            for(int j=i+i;j<=n;j+=i){
                st[j] = 1;
            }
        }
    }
}
void solve(){
    int a,b;
    cin >> a >> b;
    if(b >= 10000000){
        b = 10000000 - 1;
    }
    //除11外，回文质数的数位一定是奇数，否则一定能被11整除
    getprimes_3(b);
    if(a % 2 == 0) a++;
    for(int i=a;i<=b;i+=2){
        if(st[i]==0&&check(i)){
            cout << i << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}