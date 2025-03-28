#include <iostream>
using namespace std;
int main()
{
    int t;cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a + b == c) cout << (char)'+' << endl;
        else if(a - b == c) cout << char('-') << endl;
    }
    return 0;
}