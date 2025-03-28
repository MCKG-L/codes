#include <iostream>
#include <map>
using namespace std;
const int N = 1e6 + 10;
int a[N],n;
int ans,idx;
void find(int l,int r){
    if(l > r) return;
    int l0 = l,r0 = r;
    int mid = (l + r) / 2;
    while(l < mid && a[l] != a[mid]) l ++;
    while(r > mid && a[r] != a[mid]) r --;
    if(ans <= r - l + 1){
        ans = r - l + 1;
        idx = mid;
    }
    if(l-l0 >= ans) find(l0,l-1);
    if(r0-r >= ans) find(r+1,r0);
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    find(0,n-1);;
    cout << a[idx] << '\n' << ans << endl;
    return 0;
}