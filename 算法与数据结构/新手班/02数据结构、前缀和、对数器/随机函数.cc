#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;
int main()
{
    //rand()函数，随机返回0~MAX之间的一个整数，默认以1位种子，不加参数时每次返回的值相同
    //srand()函数指定随机数种子，一般以系统时间为种子
    srand(unsigned(time(0)));
    for(int i=0;i<20;i++){
        int ans = rand() % 10 + 1;//1 ~ 10 的数
        cout << ans << " ";
    }
    cout << endl;
    //rand()返回的最大值是 RAND_MAX == 0x7fff，即32767

    //返回0~1的小数
    double a = rand() / (RAND_MAX * 1.0);
    int cnt = 0;
    long long N = 10000000;
    double x = 0.7;
    for(int i=0;i<N;i++){
        double a = rand() / (RAND_MAX * 1.0);//0 ~ 1
        if(a < x) cnt ++;
    }
    cout << cnt / (N * 1.0) << endl;
    // cout << a << " ";

    //double a = rand() / (RAND_MAX * 1.0);
    //0~x 概率为x,调整为x*x的方法：
    cnt = 0;
    for(int i=0;i<N;i++){
        double a = rand() / (RAND_MAX * 1.0);
        double b = rand() / (RAND_MAX * 1.0);
        double ans = max(a,b);
        if(ans < x){
            cnt ++;
        }
    }
    cout << pow(x,2) << endl;
    cout << cnt / (N*1.0) << endl;

    //调整为x*x*x 
    cnt = 0;
    for(int i=0;i<N;i++){
        double a = rand() / (RAND_MAX * 1.0);
        double b = rand() / (RAND_MAX * 1.0);
        double c = rand() / (RAND_MAX * 1.0);
        double ans = max(max(a,b),c);
        if(ans < x){
            cnt ++;
        }
    }
    cout << pow(x,3) << endl;
    cout << cnt / (N*1.0) << endl;
}