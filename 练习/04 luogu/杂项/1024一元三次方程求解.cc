#include <bits/stdc++.h>
using namespace std;
float a,b,c,d;
double res(float x){
    return a*pow(x,3)+b*pow(x,2)+c*x + d;
}
void solve(){
    cin >> a >> b >> c >> d;
    for(int i=-100;i<100;i++){
        double l = i,r = i + 1;
        double x1,x2;
        x1 = res(l);x2 = res(r);
        int cnt = 0;
        if(x1 == 0) {
            cout << fixed << setprecision(2) << l << " ";
            cnt++;
        }
        if(x1 * x2 < 0){
            while(r - l >= 0.001){
                double m = (l + r) / 2;
                if(res(m) * x2 < 0){
                    l = m;
                }else{
                    r = m;
                }
            }
            cout << fixed << setprecision(2) << l << " ";
            cnt++;
        }
        if(cnt == 3) break;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}