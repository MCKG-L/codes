#include <stdlib.h>
#include <iostream>
#include <time.h>
/*
经典问题
给定一个函数f1()可以等概率的返回1~5的数字，请在不修改f1()并且
只用f1的条件下，实现等概率返回1~7的函数g();
*/
/* 解题步骤
1、均分1~5，实现等概率返回0或1的函数f2
2、利用n位二进制位，得到等概率返回0~2^n-1的函数f3
3、利用f3得到等概率返回0~6的函数f4
4、f4返回值加1即得到函数g()

*/
/*
该方法可以推广到一般情况：a~b --> c~d
给出等概率返回 17~48的函数f1，求出等概率返回11~54的函数g
*/
using namespace std;
int f1(){//1 ~ 5
    return rand()%5+1;
}
int f2(){//0 ~ 1
    int ans = 0;
    do{
        ans = f1();
    }while(ans == 3);
    return ans < 3 ? 0 : 1;
}
int f3(){//使用3个二进制位 得到0~7等概率 八分之一概率
    return (f2() << 2) + (f2() << 1) + (f2() << 0);
}
int f4(){//0~6等概率
    int ans = 0;
    do{
        ans = f3();
    }while(ans == 7);
    return ans;
}
int g(){
    return f4() + 1; 
}
int main()
{
    srand((unsigned)time(0));
    int cnt_n[8] = {};
    int N = 10000000;
    for(int i=0;i<N;i++){
        int k = g();
        cnt_n[k]++;
    }
    for(int i=0;i<8;i++){
        cout << i << ": " << cnt_n[i] << endl;
    }
    int cnt = 0;

    return 0;
}