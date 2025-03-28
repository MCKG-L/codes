#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*
给出函数f1 以不等的概率返回0和1，p概率返回0，1-p概率返回1
只是用f1求出等概率返回0和1的函数g
*/
int f(){
    return rand() / (RAND_MAX * 1.0) < 0.82 ? 0 : 1;
}
int g(){
    int ans = 0;
    do{
        ans = f();
    }while(ans == f());
    return ans;
}
int main()
{
    srand((unsigned)time(0));
    int N = 10000000;
    int cnt_n[2] = {};
    for(int i=0;i<N;i++){
        int k = g();
        cnt_n[k]++;
    }
    cout << 0 << ": " << cnt_n[0] << endl;
    cout << 1 << ": " << cnt_n[1] << endl;
}