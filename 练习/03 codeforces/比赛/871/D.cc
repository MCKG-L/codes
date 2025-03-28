#include <iostream>
using namespace std;
int a,b;
bool ans;
void func(int x){
    if(x == a){
        ans = true;
        return;
    }
    if(x > a) return;
    if(x % 2 == 0){
        func(x / 2 * 3);
    }
    func(x * 3);
}
void solve(){
    cin >> a >> b;
    ans = false;
    func(b);
    if(ans) cout << "YES";
    else cout << "NO";
    cout << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}