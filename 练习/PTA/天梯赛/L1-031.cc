#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;cin >> n;
    while(n--){
        double h,w;cin >> h >> w;
        w /= 2;
        double std = (h - 100) * 0.9;
        double offset = std * 0.1;
        double s = w - std;
        if(fabs(s) < offset) cout << "You are wan mei!" << endl;
        else if(s > 0) cout << "You are tai pang le!" << endl;
        else cout << "You are tai shou le!" << endl;
    }
    return 0;
}