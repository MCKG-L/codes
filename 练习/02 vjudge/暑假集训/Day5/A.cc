#include <iostream>
#include <map>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;cin >> s;
    string s1="";
    char p1,p2;
    p1 = s[0];
    for(int i=0;i<n;i++){
        do{
            i ++;
        }while(s[i] != p1);
        s1 += p1;
        if(i + 1 >= n) break;
        p1 = s[i+1];
    }
    cout << s1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}