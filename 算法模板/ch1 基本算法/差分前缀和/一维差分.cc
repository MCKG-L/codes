#include <iostream>
using namespace std;
const int N = 10010;
int a[N],d[N];
int n,m;
int main()
{
    cin >> n >> m;
    // for(int i=1;i<=n;i++){
    //     cin >> a[i];
    //     d[i] = a[i] - a[i-1];
    // }
    // while(m--){
    //     int l,r,c;
    //     cin >> l >> r >> c;
    //     d[l] += c;
    //     d[r+1] -= c;
    // }
    // for(int i=1;i<=n;i++){
    //     a[i] = d[i] + a[i-1];
    //     cout << a[i] << " ";
    // }
    
    //使用原数组作为差分数组
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=n;i>=1;i--) a[i] -= a[i-1];
    while(m--){
        int l,r,c;
        cin >> l >> r >> c;
        a[l] += c;
        a[r+1] -= c;
    }
    for(int i=1;i<=n;i++){
        a[i] += a[i-1];
        cout << a[i] << " ";
    }
    return 0;
}