#include <iostream>
using namespace std;
const int N = 25;
int a[N],ans;
int n,k,sum,cnt;
bool prime(int n){
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    for(int i=2;i*i<=n;i++){
        if(n % i == 0) return false;
    }
    return true;
}
void dfs(int i){
    if(cnt == k && prime(sum)){
        ans++;
        return;
    }
    if(i == n + 1 || cnt == k) return;
    //要
    sum += a[i];
    cnt++;
    dfs(i+1);
    sum -= a[i];//回溯
    cnt--;

    //不要
    dfs(i+1);
}
int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}