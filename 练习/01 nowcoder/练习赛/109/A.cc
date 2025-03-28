#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        long long n;cin >> n;
        if(n == 0) cout << "0" << endl;
        else if(n == 1) cout << "1" << endl;
        else{
            if(n & 1) cout << "3" << endl;
            else cout << "2" << endl;
        }
    }
    return 0;
}