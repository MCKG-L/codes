#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct person{
    int a,b,c,sum;
}a[N];
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].a >> a[i].b >> a[i].c;
        a[i].sum = a[i].a + a[i].b + a[i].c;
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(abs(a[i].a-a[j].a)<=5&&abs(a[i].b-a[j].b)<=5&&abs(a[i].c-a[j].c)<=5){
                if(abs(a[i].sum-a[j].sum)<=10){
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}