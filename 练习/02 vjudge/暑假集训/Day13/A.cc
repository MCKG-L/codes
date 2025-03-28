#include <iostream>
using namespace std;
int main()
{
    int t;cin >> t;
    while(t--){
        int a,b,c,x,y;
        cin >> a >> b >> c >> x >> y;
        int r1 = max(0,x-a);
        int r2 = max(0,y-b);
        if(c >= r1 + r2){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}