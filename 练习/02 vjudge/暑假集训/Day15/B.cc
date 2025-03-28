#include <iostream>
using namespace std;
void solve(){
    int ans = 0;
    int n;cin >> n;
    string str;cin >> str;
    int s = 1;
    for(int i=1;i<n;i++){
        if(str[i] == str[i-1]){
            s ++;
        }else{
            ans = max(ans,s);
            s = 1;
        }
    }
    cout << max(ans,s)+1 << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}