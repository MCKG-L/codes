#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;cin >> n;
    while(n--){
        string s;cin >> s;
        double h;cin >> h;
        if(s == "F")
            cout << fixed << setprecision(2) << h*1.09 << endl;
        else
            cout << fixed << setprecision(2) << h/1.09 << endl;
    }
    return 0;
}