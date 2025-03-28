#include <bits/stdc++.h>
using namespace std;
/*
map + 前缀和 解决求满足条件的子数组个数问题
在map中记录前缀和数组每一项（键）出现的次数（值），对于a[i]，在map中查找
是否出现过a[i]-k,出现的次数（值）则为满足条件的组数（ans+=m[a[i]-k])
注意m[0] = 1  会有a[i] == k的情况
*/
int main()
{
    long long x,n;
    cin >> n >> x;
    long long a[n+1] = {};
    map<long long,long long> m;
    m[0] = 1;
    long long ans = 0;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
        //m[a[i]]++; k可能为0，避免将空数组计数在内,应该先判断再记录
        if(m.count(a[i] - x)){
            ans += m[a[i] - x];
        }
        m[a[i]]++;//后记录
    }
    cout << ans;
    return 0;
}