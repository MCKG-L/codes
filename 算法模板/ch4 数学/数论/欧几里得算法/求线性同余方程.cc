#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long ll;
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y -= a / b * x;
    //或
    /*
    int d = exgcd(b,a%b,x,y);
    int t = y;
    y = x - a / b * y;
    x = t;
    */
    return d;
}
int main()
{
    int n;cin >> n;
    while(n--){
        int a,b,m;
        scanf("%d %d %d",&a,&b,&m);
        int x,y;
        int d = exgcd(a,m,x,y);
        if(b % d) puts("impossible");
        else printf("%d\n",(ll)x*(b/d)%m);
    }
    return 0;
}