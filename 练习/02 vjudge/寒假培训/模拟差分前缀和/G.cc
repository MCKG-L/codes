#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for(long long i=1;i<n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    long long maxn = 0;
    if(k == 0) cout << a[n-1] << endl;
    else if(k < n-1){
        for(long long  i=k;i<n;i++){
        maxn = max(maxn,a[i]-a[i-k]);
        }
        cout << a[n-1] - maxn << endl;
    }else {
        cout << "0" << endl;
    }
    return 0;

}