#include <iostream>
using namespace std;
int main()
{
    int a,b;
    int n1=0,n2=0;
    cin >> a >> b;
    int n;cin >> n;
    while(n--){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = x1 + x2;
        if(y1 == sum && y2 == sum) continue;
        if(y1 == sum) n1++,a--;
        if(y2 == sum) n2++,b--;
        if(a < 0){
            cout << 'A' << endl << n2;
            break;
        }else if(b < 0){
            cout << 'B' << endl << n1;
            break;
        }
    }
    return 0;
}