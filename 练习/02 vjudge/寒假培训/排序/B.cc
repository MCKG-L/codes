#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+5;
//该方法超时！
inline int read(){
    int x=0,f=1;
    char c = getchar();
    while(c<'0'||c>'9'){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9'){
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int a[N];
int find(int l,int r,int k){
    if(l >= r) return a[l];
    int i = l,j = r,mask = a[l];
    while(i < j){
        while(a[j] > mask && i < j) j--;
        while(a[i] <= mask && i < j) i++;
        if(i < j) swap(a[i],a[j--]);
    }
    if(i - l + 1 >= k) return find(l,j,k);
    else return find(i+1,r,k-(i-l+1));
}
void solve(){
    int n,k;
    //cin >> n >> k;
    //scanf("%d %d",&n,&k);
    n = read();
    k = read();
    for(int i=0;i<n;i++) a[i] = read();
    //cout << find(0,n-1,k+1);
    printf("%d",find(0,n-1,k+1));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}