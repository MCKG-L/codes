#include <bits/stdc++.h>
using namespace std;
struct stu{
    int a,b,c;
    int num,sum;
};
bool cmp(stu s1,stu s2){
    if(s1.sum == s2.sum){
        if(s1.a == s2.a) return s1.num < s2.num;
        else return s1.a > s2.a;
    }else{
        return s1.sum > s2.sum;
    }
}
void solve(){
    int n;cin >> n;
    stu a[n];
    for(int i=0;i<n;i++){
        cin >> a[i].a >> a[i].b >> a[i].c;
        a[i].num = i + 1;
        a[i].sum = a[i].a + a[i].b + a[i].c;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<5;i++){
        cout << a[i].num << " "  << a[i].sum << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}