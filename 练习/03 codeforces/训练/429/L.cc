#include <iostream>
#include <map>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int n;cin >> n;
    while(n--){
        int l,r,c;
        cin >> l >> c >> r >> c;
        a[l] ++;
        a[r] --;
    }
    for(int i=1;i<N;i++) a[i] += a[i-1];
    int ans = 0;
    for(int i=1;i<N;i++){
        if(a[i]) ans ++;
    }
    cout << ans << endl;
    return 0;
}