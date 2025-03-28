#include <bits/stdc++.h>
using namespace std;
const int N = 100;
struct stu{
    string s;
    int y,m,d,n;
}a[N];
bool cmp(stu s1,stu s2){
    if(s1.y == s2.y){
        if(s1.m == s2.m){
            if(s1.d == s2.d){
                return s1.n > s2.n;
            }else{
                return s1.d < s2.d;
            }
        }else{
            return s1.m < s2.m;
        }
    }else{
        return s1.y < s2.y;
    }
}
void solve(){
    int n;cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].s >> a[i].y >> a[i].m >> a[i].d;
        a[i].n = i;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        cout << a[i].s << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}