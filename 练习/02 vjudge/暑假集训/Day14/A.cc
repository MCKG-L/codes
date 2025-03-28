#include <iostream>
#include <set>
using namespace std;
const int N = 1e5 + 10;
int n;
set<char> st;
void solve(){
    cin >> n;
    string s;cin >> s;
    for(int i=0;i<n;i++){
        st.insert(s[i]);
        if(st.size() == 3){
            cout << i + 1 << endl;
            return;
        }
    }

}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}