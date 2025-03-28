#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
情形4：计算的组合数结果不取模，而是用高精度把答案直接输出出来
*/
const int N = 5010;
int pr[N],cnt;
int sum[N];
bool st[N];
void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) pr[cnt++] = i;
        for(int j=0;pr[j]<=n/i;j++){
            st[pr[j]*i] = true;
            if(i % pr[j] == 0) break;
        }
    }
}
//求a!中p出现的次数
int get(int n,int p){
    int ans = 0;
    while(n){
        ans += n / p;
        n /= p;
    }
    return ans;
}
vector<int> mul(vector<int> a,int b){
    vector<int> c;
    int t = 0;
    for(int i=0;i<a.size();i++){
        t += a[i]*b;
        c.push_back(t%10);
        t /= 10;
    }
    while(t){
        c.push_back(t%10);
        t /= 10;
    }
    return c;
}
int main()
{
    int a,b;
    cin >> a >> b;
    get_primes(a);
    for(int i=0;i<cnt;i++){
        int p = pr[i];
        sum[i] = get(a,p)-get(b,p)-get(a-b,p);
    }
    vector<int> ans;
    ans.push_back(1);
    for(int i=0;i<cnt;i++){
        for(int j=0;j<sum[i];j++){
            ans = mul(ans,pr[i]);
        }
    }
    for(int i=ans.size()-1;i>=0;i--) cout << ans[i];
    puts("");
    return 0;
}