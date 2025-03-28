#include <iostream>
#include <set>
using namespace std;
int n;
void solve(){
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        s.insert(x);
    }
    if(s.size() == 1){
        cout << n << endl;
    }
    else{
        cout << 1 << endl;
    }
    
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}