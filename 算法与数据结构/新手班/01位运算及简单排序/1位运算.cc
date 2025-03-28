#include <iostream>
using namespace std;
/* 位运算
1、按位与 & : 同为得1，其余得0
2、按位或 | : 有1得1，无1得0
3、按位异或 ^ : 相同为0，不同为1
4、按位取反 ~ ： 1变0，0变1
5、左移 : <<
6、带符号右移 : >>
7、无符号右移 : /
*/
void printB(int n){
    for(int i=31;i>=0;i--){
        cout << ((n & (1 << i)) == 0 ? "0" : "1");
    }
    /*
    1左移i位，则只有第i位为1，其余位为0
    与n进行按位与，如果n的第i位是0则得到0，如果不是0，则得到的数不是0
    */
    cout << endl;
}
int main()
{
    //n 取反加1 得到n的相反数
    //0 取反加1 得到0
    int a,b;
    // cin >> a >> b;
    a = 1236475863;
    b = 2147003823;
    printB(a);
    printB(b);
    cout << "---------------------------------" << endl;
    printB(a & b);
    int c = INT_MIN;
    //系统最小取反加1后还是系统最小（闭环）
    cout << c << endl << (~c + 1);
    return 0;
}