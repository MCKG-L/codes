#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    int maxn,minn,midn;
    maxn = max(a,max(b,c));
    minn = min(a,min(b,c));
    midn = a + b + c - maxn - minn;
    if(minn + midn <= maxn){
        cout << "Not triangle";
    }else{
        int l = minn*minn + midn*midn;
        int r = maxn * maxn;
        if(l < r){
            cout << "Obtuse triangle" << '\n';
        }else if(l == r){
            cout << "Right triangle" << '\n';
        }else{
            cout << "Acute triangle" << '\n';
        }
        if(minn == midn){
            cout << "Isosceles triangle" << '\n';
            if(midn == maxn){
                cout << "Equilateral triangle";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}