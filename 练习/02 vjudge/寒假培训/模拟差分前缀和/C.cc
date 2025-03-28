// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long//如果这样写，则下面的main函数的返回值必须写成signed
// // signed main()
// int main()
// {
//     long long x,n;
//     cin >> n >> x;
//     long long a[n+1] = {};
//     map<long long,int> m;
//     m[0] = 1;
//     int ans = 0;
//     for(int i=1;i<=n;i++){
//         cin >> a[i];
//         a[i] += a[i-1];
//         if(m.count(a[i] - x)){
//             ans += m[a[i] - x];
//         }
//         m[a[i]]++;
//     }
//     cout << ans;
//     return 0;
// }
//快慢指针法
/*
此题的数组为整数，前缀和单调增加

遇到单调不减的类型，可以考虑用双指针（l 和 r），一个l最多对应一个满足题意的情况
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    long long a[n+1] = {};
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    int l=0,r=1,ans=0;
    while(l!=n){
        while(a[r]-a[l]<k && r<n) r++;
        if(a[r] - a[l] == k){
        	ans++;
		}
		l++;
    }
    cout << ans;
    return 0;
}