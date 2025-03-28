#include <bits/stdc++.h>
using namespace std;
const int N = 1048576;
long long a[N];
//要用并查集写
int main()
{
    memset(a,-1,sizeof(a));
    int q;cin >> q;
    while(q--){
        long long t,x;cin >> t >> x;
        if(t == 2) cout << a[x%N] << endl;
        else if(t == 1){
        	long long h = x;
        	while(a[h%N] != -1) h++;
        	a[h%N] = x;
		}
    }
    return 0;
}