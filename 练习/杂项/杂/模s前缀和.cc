#include <iostream>
using namespace std;
const int N = 5e4 + 10;
int a[N];
int main()
{
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
        a[i] %= 7;
    }
    int ans = -1;
    for(int i=0;i<7;i++){
        int l = 0;
        while(a[l]!=i && l < n)l++;
        int r = n;
        while(a[r]!=i && l < r)r--;
        ans = max(ans,r-l);
    }
    cout << ans;
}