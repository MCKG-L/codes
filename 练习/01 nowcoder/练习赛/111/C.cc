#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    while(n--){
        int m,x;
        cin >> m >> x;
        cout << (m/(m/x)-m/(m/x+1)) << endl;
    }
    return 0;
}