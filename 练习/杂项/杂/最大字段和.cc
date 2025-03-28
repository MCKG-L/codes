#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    int ans = -0xffffff,s = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(s + x > x){
            s += x;
        }else{
            s = x;
        }
        ans = max(ans,s);
    }
    cout << ans;
    return 0;
}