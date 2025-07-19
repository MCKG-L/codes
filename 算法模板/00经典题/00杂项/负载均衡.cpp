#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;
/* acwing 浙江大学机试题
有 N个石子堆成一堆。
你可以对石子堆进行拆分操作，具体为选中一堆现有石子堆，将其中的石子分为两堆（不能为空）。
此外，在任何时候，最小石子堆的石子数量都必须严格大于最大石子堆的石子数量的一半。
我们希望，通过将石子堆进行拆分，最终可以满足：
1.石子堆的总数量尽可能大，不妨设这个总数量的最大可能值为 M
2.满足上一条要求的前提下，最大石子堆石子数量与最小石子堆石子数量之差尽可能小，不妨设这个差的最小可能值为 D
请你计算并输出 M
和 D 的值。
*/
void solve(){
    int n;cin >> n;
    int M = 1,ans = inf;
    /*
    a为当前最大值，b为当前次大值，y为合理的分解之后得到的较小值
    max((a + 3) / 3, b / 2 + 1) <= y <= a / 2
    */
    auto dfs = [&](auto dfs,priority_queue<int> heap,int cnt,int Min,int x1,int x2)->void{
        heap.push(x1);heap.push(x2);
        int a = heap.top(),b = -inf;heap.pop();
        if(heap.size()) b = heap.top();
        if(cnt > M){
            M = cnt;
            ans = a - Min;
        }else if(cnt == M){
            ans = min(ans,a-Min);
        }
        int l = max((a + 3) / 3,b / 2 + 1),r = a / 2;
        
        for(int x=l;x<=r;x++) dfs(dfs,heap,cnt+1,min(Min,x),x,a-x);
    };
    int l = (n + 3) / 3,r = n / 2;
    priority_queue<int> heap;
    for(int i=l;i<=r;i++){
        if(i + i == n){
            if(M <= 2){
                M = 2,ans = 0;
            }
            continue;
        }
        dfs(dfs,heap,2,i,i,n-i);
    }
    cout << M << ' ' << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}
