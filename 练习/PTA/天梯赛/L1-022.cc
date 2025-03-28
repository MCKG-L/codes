#include <iostream>
using namespace std;
int main()
{
    int cnt1=0,cnt2=0;
    int n;cin >> n;
    while(n--){
        int x;cin >> x;
        if(x & 1) cnt1++;
        else cnt2++;
    }
    cout << cnt1 << " " << cnt2 << endl;
    return 0;
}