#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int k = 0;
    for(int i=0;i<n;i++){
        if(a[i] > k + 1) break;
        k += a[i];
    }
    cout << k + 1 << endl;
    return 0;
}