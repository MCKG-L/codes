#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e6+5;
int a[N];
int main()
{
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    sort(a,a+m);
    for(int i=0;i<m;i++){
        cout << a[i] << " ";
    }
    return 0;
}