#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e4+10;
struct p{
    string s;int n;
}a[N];
bool cmp(p p1, p p2){
    return p1.n < p2.n;
}
int m_find(int n,double x){
    int l = 0,r = n - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(a[mid].n >= x) r = mid;
        else l = mid + 1;
    }
    int ll = l;
    while(a[ll].n >= x) ll--;
    if(x-a[ll].n < a[l].n-x) return ll;
    else return l;
}
int main()
{
    int n;cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i].s >> a[i].n;
        sum += a[i].n;
    }
    double av = sum*1.0/n/2;
    sort(a,a+n,cmp);
    int l = m_find(n,av);
    cout << (int)av << " " << a[l].s << endl;
    return 0;
}