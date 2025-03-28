#include <bits/stdc++.h>
using namespace std;
void solve(){
    double m,h,k;
    cin >> m >> h;
    k = m / (h * h);
    if(k < 18.5){
        cout << "Underweight";
    }else if(k < 24){
        cout << "Normal";
    }else{
        cout << k << '\n' << "Overweight";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}