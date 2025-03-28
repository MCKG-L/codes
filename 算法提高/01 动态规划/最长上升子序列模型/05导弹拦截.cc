#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int n,a[N],f[N],g[N];
int main()
{
    while(cin >> a[n]) n++;
    int len1 = 0,len2 = 0;
    f[0] = 2e9,g[0] = -2e9;
    for(int i=0;i<n;i++){
        if(a[i] <= f[len1]) f[++len1] = a[i];
        else *upper_bound(f,f+len1,a[i],[&](int a,int b){return a>b;}) = a[i];
        if(a[i] > g[len2]) g[++len2] = a[i];
        else *lower_bound(g,g+len2,a[i]) = a[i];
    }
    cout << len1 << '\n' << len2 << endl;
    return 0;
}