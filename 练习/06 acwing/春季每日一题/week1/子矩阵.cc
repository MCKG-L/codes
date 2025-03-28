#include <iostream>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1010,mod = 998244353;
int n,m,A,B;
int rmax[N][N],rmin[N][N];
int w[N][N],q[N];
//单调队列求区间最大值
void get_max(int a[],int b[],int tol,int k){
    int hh = 0,tt = -1;
    for(int i=0;i<tol;i++){
        if(hh <= tt && q[hh] <= i - k) hh ++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[++ tt] = i;
        if(i >= k - 1) b[i] = a[q[hh]];
    }
}
// void get_max(int a[], int b[], int tot, int k)
// {
//     int hh = 0, tt  = -1;
//     for(int i = 0; i < tot; i ++)
//     {
//         if(hh <= tt && q[hh] <= i - k) hh ++;
//         while(hh <= tt && a[q[tt]] <= a[i]) tt --;
//         q[++ tt] = i;
//         // y总代码这里没加这个if判断，我认为加了比较好，不会出现窗口不合法的情况
//         // 如当i = 1，窗口为[-1, 1]
//         if(i >= k - 1) b[i] = a[q[hh]]; 
//     }
// }
//单调队列求区间最小值
void get_min(int a[],int b[],int tol,int k){
    int hh = 0,tt = -1;
    for(int i=0;i<tol;i++){
        if(hh <= tt && q[hh] <= i - k) hh ++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt --;
        q[++ tt] = i;
        if(i >= k - 1) b[i] = a[q[hh]];
    }
}

// void get_min(int a[], int b[], int tot, int k)
// {
//     int hh = 0, tt = -1;
//     for(int i = 0; i < tot; i ++)
//     {
//         if(hh <= tt && q[hh] <= i - k) hh ++;
//         while(hh <= tt && a[q[tt]] >= a[i]) tt --;
//         q[++ tt] = i;
//         if(i >= k - 1) b[i] = a[q[hh]]; 
//     }
// }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> A >> B;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> w[i][j];
        }
    }
    for(int i=0;i<n;i++){
        get_max(w[i],rmax[i],m,B);
        get_min(w[i],rmin[i],m,B);
    }
    
    int ans = 0;
    int a[N],b[N],c[N];
    for(int i=B-1;i<m;i++){
        for(int j=0;j<n;j++) a[j] = rmax[j][i];
        get_max(a,b,n,A);
        for(int j=0;j<n;j++) a[j] = rmin[j][i];
        get_min(a,c,n,A);
        
        for(int j=A-1;j<n;j++){
            ans = (ans + (ll)b[j] * c[j]) % mod;
            cout << b[j] << ' ' << c[j] << endl;
            
        }
    }
    cout << ans << endl;
    return 0;
}