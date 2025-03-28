#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
double dis(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void solve(){
    double x1f,y1f,x2f,y2f;
    double x1s,y1s,x2s,y2s;
    cin >> x1f >> y1f >> x2f >> y2f;
    cin >> x1s >> y1s >> x2s >> y2s;
    double x1 = (x1f + x2f) / 2,y1 = (y1f + y2f) / 2;
    double x2 = (x1s + x2s) / 2,y2 = (y1s + y2s) / 2;
    double r = dis(x1s,y1s,x2s,y2s)/2;
    double man = fabs(x1-x2) + fabs(y1-y2);
    double ans = man - sqrt(2) * r;
    printf("%.10f\n",ans);
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}