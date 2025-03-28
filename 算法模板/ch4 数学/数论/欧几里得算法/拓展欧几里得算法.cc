/*
裴蜀定理：有一对正整数a，b，那么一定存在整数x，y 使得ax + by = gcd(a,b)
ax + by = kgcd(a,b),ax + by 一定是gcd(a,b)的倍数，则ax+by最小为gcd(a,b)

*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
//ax + by = gcd(a,b) 求x,y
int exgcd(int a,int b,int &x,int &y){//返回最大公约数
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
        int a,b,x,y;
        scanf("%d %d",&a,&b);
        exgcd(a,b,x,y);
        printf("%d %d\n",x,y);
    }
    return 0;
}