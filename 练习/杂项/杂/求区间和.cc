#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    int m;cin >> m;
    while(m--){
        int x,y;
        cin >> x >> y;
        cout << a[y] - a[x-1] << endl;
    }
    return 0;
}
