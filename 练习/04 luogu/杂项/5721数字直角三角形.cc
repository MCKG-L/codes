#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    int mask = 1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            if(mask < 10){
                cout << 0 << mask++;
            }else cout << mask++;
        }
        cout << "\n\0"[i == n-1];
    }
    return 0;
}