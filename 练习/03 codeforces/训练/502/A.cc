#include <iostream>
using namespace std;
bool mask[10];
int main()
{
    int n;cin >> n;
    int ans[n] = {};
    int k = 0;
    ans[0] = 1;mask[1] ^= 1;
    for(int i=1;i<n;i++){
        while(mask[k]) k++;
        ans[i] = k;
        mask[k] ^= 1;
    }
    if(n > 10){
        cout << -1 << endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}