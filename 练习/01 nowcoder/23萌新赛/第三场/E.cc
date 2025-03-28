#include <iostream>
#include <map>
using namespace std;
bool func(int x){
    for(int i=1;i<=x/i;i++){
        if(i * i == x) return true;
    }
    return false;
}
int main()
{
    int n;cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(func(x)) ans ++;
    }
    cout << ans << endl;
    return 0;
}