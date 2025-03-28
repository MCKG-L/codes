#include <iostream>
#include <vector>
using namespace std;
const int N = 110;
string name[N];
void solve(){
    int n;cin >> n;
    int min_n = 1e9 + 10;
    int x,pos = 0;
    for(int i=0;i<n;i++){
        cin >> name[i] >> x;
        if(x < min_n){
            min_n = x;
            pos = i;
        }
    }

    for(int i=pos;i<n;i++){
        cout << name[i] << endl;
    }
    for(int i=0;i<pos;i++){
        cout << name[i] << endl;
    }
}
int main()
{
    // int t;cin >> t；
    int t = 1;
    while(t--) solve();
    return 0;
}