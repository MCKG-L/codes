#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int N = 20010,P = 131;
int n,m;
char str[N];
ull p[N],h[N];
ull get(int l,int r){
    return h[r] - h[l-1] * p[r-l+1];
}
bool check(int mid){
    unordered_set<ull> hash;
    for(int i=1;i+mid-1<=n;i++){
        hash.insert(get(i,i+mid-1));
    }
    for(int i=n+1;i+mid-1<=m+n;i++){
        if(hash.count(get(i,i+mid-1))) return true;
    }
    return false;
}
int main()
{
    cin >> str + 1;
    n = strlen(str+1);
    cin >> str + n + 1;
    m = strlen(str+n+1);
    p[0] = 1;
    for(int i=1;i<=n+m;i++){
        p[i] = p[i-1] * P;
        char c = str[i];
        if(isdigit(c)){
            if(i <= n) c = '#';
            else c = '$';
        }
        h[i] = h[i-1] * P + c;
    }
    //二分答案
    int l = 0,r = min(m,n);
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
    return 0;
}