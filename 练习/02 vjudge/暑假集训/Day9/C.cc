#include <iostream>
#include <cmath>
#include <algorithm>
#define int long long
#define double long double
using namespace std;
const double eps = 1e-20l;
const int N = 2e5 + 10;
struct Node{
    int id;
    double s;
}a[N];
int n,A,B;
signed main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A >> B;
        double s = 1.0l*A/(A+B);
        a[i] = {i+1,s};
    }
    sort(a,a+n,[&](Node p1,Node p2){
        if(fabsl(p1.s-p2.s) < eps) return p1.id < p2.id;
        // if(p1.s - p2.s < )
        else return p1.s > p2.s;
        // if(p1.s != p2.s) return p1.s > p2.s;
        // else return p1.id < p2.id;
    });
    for(int i=0;i<n;i++){
        cout << a[i].id << ' ';
    }
    return 0;
}
