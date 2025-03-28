#include <bits/stdc++.h>
using namespace std;
/*
  求 A^B的最后三位数表示的整数
*/
//朴素做法 很容易溢出
long long normalPower1(long long base,long long power){
    long long result=1;
    for(int i=1;i<=power;i++){
        result=result*base;
    }
    return result%1000;
}

//取模优化 (a*b)%c = (a%c * b%c)%c
long long normalPower(long long base,long long power){
    long long result=1;
    for(int i=1;i<=power;i++){
        result=result*base;
        result=result%1000;
    }
    return result%1000;
}
//快速幂算法
long long fastPower1(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 0) {
            //如果指数为偶数
            power = power / 2;//把指数缩小为一半
            base = base * base % 1000;//底数变大成原来的平方
        } else {
            //如果指数为奇数
            power = power - 1;//把指数减去1，使其变成一个偶数
            result = result * base % 1000;//此时记得要把指数为奇数时分离出来的底数的一次方收集好
            power = power / 2;//此时指数为偶数，可以继续执行操作
            base = base * base % 1000;
        }
    }
    return result;
}
//快速幂算法优化1
long long fastPower2(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base % 1000;
        }
        power = power / 2;
        base = (base * base) % 1000;
    }
    return result;
}
//快速幂算法最终优化 位运算优化
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % 1000;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % 1000;
    }
    return result;
}
//通用模板 (a^k)%p
int qmi(int a,int k,int p){
    int ans = 1;
    while(k){
        if(k & 1) ans = (long long)ans * a % p;
        k >>= 1;
        a = (long long)a * a % p;
    }
    return ans;
}
int main()
{
    clock_t start,end;
    long long base,power;
    cin >> base >> power;
    start = clock();
    cout << fastPower(base,power) << endl;
    end = clock();
    cout << "time : " << double(end - start)/CLOCKS_PER_SEC << "s";
    return 0;
}