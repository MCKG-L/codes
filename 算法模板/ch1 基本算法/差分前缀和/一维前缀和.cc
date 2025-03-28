#include <iostream>
using namespace std;
const int N = 100010;
int a[N],n,m;
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    while(m--){
        int l,r;
        cin >> l >> r;
        cout << a[r]-a[l-1] << endl;
    }
    return 0;
}