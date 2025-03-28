#include <iostream>
using namespace std;
/*
异或运算：不进位的相加运算 即按位相加，相同为0，不同为1
基本性质：0 ^ x = x,x ^ x = 0;

*/
int main()
{
    //异或运算的一些简单应用：
    //1、不适用其他变量实现交换两个数的值
    int a,b;
    cin >> a >> b;
    a = a ^ b; //a = A ^ B
    b = a ^ b; //b = A ^ B ^ B = A
    a = a ^ b; //a = A ^ B ^ A = B
    cout << a << ' ' << b << endl;

    //2、找到数组中唯一的出现奇数次的数 利用 x ^ x = 0;
    int arr[5] = {1,1,2,2,3};
    int s = 0;
    for(int i=0;i<5;i++){
        s ^= arr[i];
    }
    cout << s << endl;

    
    /*
    3、找到数组中唯二的出现次数为奇数的两个数 设为a,b
    异或和为 s = a ^ b 则s的二进制位中至少有一个是1 (a != b)
    lowbit()函数找到s中最右侧1的位置k（该位置为1，其他位为0）t
    lowbit函数 实现为 x & (~x + 1) 即 x & -x
    让t与数组中所有第k位为1的数求异或，得出的结果即为a或b
    */
    int arr2[10] = {1,1,2,2,3,3,4,4,5,6};
    int s_xor = 0;
    for(int i : arr2) s_xor ^= i;
    // int t = lowbit(s_xor);
    int t = s_xor & -s_xor;
    int m = 0;
    for(int i : arr2){
        if(i & t != 0) m ^= i;
    }
    cout << m << ' ' << (m ^ s_xor) << endl;
}