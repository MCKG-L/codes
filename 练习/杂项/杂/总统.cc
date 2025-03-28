#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 25;
struct p{
    int id;
    string s;
}a[N];
bool cmp(p p1, p p2){
    if(p1.s.size() == p2.s.size()){
        return p1.s < p2.s;
    }else{
        return p1.s.size() < p2.s.size();
    }
}
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].s;
        a[i].id = i + 1;
    }
    sort(a,a+n,cmp);
    cout << a[n-1].id << '\n' << a[n-1].s;
    return 0;
}