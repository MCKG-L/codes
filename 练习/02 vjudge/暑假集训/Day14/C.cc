#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int cnt[N];
int n;
vector<int> ans;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++){
        int u;cin >> u;
        a[i] = u;
    }
    int p = 1;
    while(cnt[p] <= 1){
        cnt[p] ++;
        p = a[p];
    }
    int pos = p;
    ans.push_back(p);
    p = a[p];
    while(p != pos){
        ans.push_back(p);
        p = a[p];
    }
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i << ' ';
    }
    return 0;
}