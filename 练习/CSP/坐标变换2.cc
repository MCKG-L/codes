#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<double> pre1(n+10,1.0),pre2(n+10);
    for(int i=1;i<=n;i++){
        double a = 1.0,b = 0.0;
        int op;double x;
        cin >> op >> x;
        if(op == 1) a = x;
        else b = x;
        pre1[i] = pre1[i-1] * a;
        pre2[i] = pre2[i-1] + b;
    }
    
    for(int i=0;i<m;i++){
        int l,r;
        double x,y;
        cin >> l >> r >> x >> y;
        double a = pre1[r] / pre1[l-1];
        double b = pre2[r] - pre2[l-1];
        x = x * a;y = y * a;
        double tx = x,ty = y;
        x = tx * cos(b) - ty * sin(b);
        y = tx * sin(b) + ty * cos(b);
        printf("%.3f %.3f\n",x,y);
    }
    return 0;
}