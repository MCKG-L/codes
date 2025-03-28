#include <iostream>
using namespace std;
int main()
{
    int s,t,x;
    cin >> s >> t >> x;
    if(s < t){
        if(x >= s && x < t) cout << "Yes";
        else cout << "No";
    }else{
        if(x < 24 && x >= s) cout << "Yes";
        else{
            if(x >= 0 && x < t) cout << "Yes";
            else cout << "No";
        }
    }
    return 0;
}