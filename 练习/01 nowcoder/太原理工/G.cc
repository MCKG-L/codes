#include <iostream>
using namespace std;
const int N = 21;
pair<int,int> p[N];
int n,t,ans,sum,tt;
void dfs(int i){
    if(i >= n){
        ans = max(ans,sum);
        return;
    }
    //做
    if(tt + p[i].second <= t){
        sum += p[i].first;
        tt += p[i].second;
        dfs(i+1);
        sum -= p[i].first;
        tt -= p[i].second;
    }
    //不做
    dfs(i+1);
}
int main()
{
    cin >> n >> t;
    for(int i=0;i<n;i++) {
        cin >> p[i].first >> p[i].second;
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}