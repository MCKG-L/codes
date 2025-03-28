#include <iostream>
#include <stack>
using namespace std;
/*
状态表示：f[i] 表示以第i个数结尾的最长上升子序列
*/
const int N = 1010;
int a[N],n;
int dp[N];
int g[N];//记录转移的路径
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        dp[i] = 1;g[i] = 0;
        for(int j=1;j<i;j++){
            if(a[i] > a[j]){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    g[i] = j;
                }
            } 
        }
    }
    int k = 1;
    for(int i=1;i<=n;i++){
        if(dp[k] < dp[i]){
            k = i;
        }
    }
    cout << dp[k] << endl;
    //路径
    stack<int> sk;
    for(int i=0,len = dp[k];i<len;i++){
        // cout << a[k] << ' ';
        sk.push(a[k]);
        k = g[k];
    }
    while(sk.size()){
        cout << sk.top() << ' ';
        sk.pop();

    }
    return 0;
}