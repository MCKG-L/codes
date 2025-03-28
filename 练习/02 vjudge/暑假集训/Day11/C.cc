#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
vector<int> p;
int a[N];
int n;
void solve(){
    p.clear();
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        p.push_back(a[i]);
    }
    sort(a,a+n);
    int max1 = a[n-1],max2 = a[n-2];
    for(auto i : p){
        if(i == max1) cout << i - max2 << ' ';
        else cout << i - max1 << ' ';
    }
    cout << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}