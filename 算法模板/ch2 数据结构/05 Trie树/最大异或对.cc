#include <iostream>
using namespace std;
/*
从n个数中任意选取两个数，使得其异或的值最大
利用Trie数存储整数的二进制形式
*/
const int N = 100010,M = 31 * N;
int n,a[N];
int son[M][2],idx;
void insert(int x){
    int p = 0;
    for(int i=30;i>=0;i--){
        int u = x >> i & 1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}
void insett(int x){
    int p = 0;
    for(int i=30;i>=0;i--){
        int u = x >> i & 0x1;
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }

}
int qu(int x){
    int ans = 0,p = 0;
    for(int i=30;i>=0;i--){
        int u = x >> i & 0x1;
        if(son[p][!u]){
            if(!u) ans |= 1 << i;
        }else{
            if(u) ans |= 1 << i;
        }
        p = son[p][u];
    }
    return ans;
}
int query(int x){
    int p = 0;
    int ans = 0;
    for(int i=30;i>=0;i--){
        int u = x >> i & 1;
        if(son[p][!u]){
            p = son[p][u];
            ans = ans * 2 + !u;
        }
        else{
            p = son[p][u];
            ans = ans * 2 + u;
        }
    }
    return ans;
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        insert(a[i]);
        int t = query(a[i]);
        ans = max(ans,a[i]^t);
    }
    cout << ans << endl;
    return 0;
}