#include <iostream>
using namespace std;
int main()
{
    int x;cin >> x;
    int k = 0,t = x;
    while(t){
        k ++;
        t /= 10;
    }
    // cout << k << endl;
    if(k <= 3){
        cout << x << endl;
        return 0;
    }
    string s = to_string(x);
    for(int i=0;i<k;i++){
        if(i < 3) cout << s[i];
        else cout << 0;
    }
    return 0;
}