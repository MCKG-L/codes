#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int h,m;char c;
    cin >> h >> c >> m;
    if(h >= 0 && h <= 12){
        cout << "Only ";cout << setfill('0') << setw(2) << h;
        cout << ":";cout << setfill('0') << setw(2) << m;
        cout << ".  Too early to Dang.";
    }else{
        int cnt = h % 12;
        if(m != 0) cnt++;
        for(int i=0;i<cnt;i++){
            cout << "Dang";
        }
    }
    return 0;
}