#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int a[N],cnt[N];
int n;
//在有向图中找到一个环
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int u = 1;
    while(cnt[u] <= 1){
        cnt[u] ++;
        u = a[u];
    }
    vector<int> ans;
    ans.push_back(u);
    int x = a[u];
    while(x != u){
        ans.push_back(x);
        x = a[x];
    }
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i << ' ';
    }
    return 0;
}