#include <iostream>
#include <bitset>
using namespace std;
/*
压位 bitset<100000> s;
支持位运算
    ~ & | ^ 
    >> <<
    == !=
    []
    count() 返回有多少1
    any() 判断是否至少有一个1
    none() 判断是否全部位0

    set() 将所有位置1
    set(k,v) 将第k位变成v
    reset() 将所有位置变成0
    flip() 等价于取反
    flip(k) 将第k位取反
    

*/
int main()
{
    bitset<1000> p;
    p.set();
    for(int i=0;i<200;i++){
        p.flip(2*i+1);
    }
    for(int i=0;i<1000;i++){
        cout << p[i] << ' ';
    }
    return 0;
}