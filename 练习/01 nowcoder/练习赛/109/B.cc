#include <iostream>
using namespace std;
const int N = 1e6+10;
int a[N];
int n;
int main()
{
    cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0,j=0;i<n;i+=(max(j-1,1))){
        int s = a[i];
        for(j=0;i+j<n;j++){
            if(a[i+j]-s != ((j+1)/2*(j&1?1:-1)))break;
        }
        ans = max(ans,j);
    }
    cout << ans << endl;
    return 0;
}