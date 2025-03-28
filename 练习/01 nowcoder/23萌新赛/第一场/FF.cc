#include <iostream>
#include <map>
using namespace std;
const int N = 1e5 + 10;
//置换环
int p[N],a[N];
map<int,int> mp;
int n;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        merge(a[i],i);
    }
    int ans = n;
    //统计环的个数
    for(int i=1;i<=n;i++){
        mp[find(a[i])]++;
    }
    ans -= mp.size();
    cout << ans << endl;
    return 0;
}