#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    int t = 1;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a + b == c) cout << (char)('+') << endl;
        else cout << (char)('-') << endl;
    }
    return 0;
}