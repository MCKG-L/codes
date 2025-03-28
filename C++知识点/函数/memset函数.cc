#include <iostream>
#include <cstring>
using namespace std;
/*
头文件：cstring
注意 memset的赋值方式为按照字节进行填充
例如：int型数组 4个字节 memset(a,-1,sizeof(a)) 可以将数组的每个元素赋值为-1
因为-1的二进制补码为：1111 int数组的每个元素都被赋值为1111111111111111,其值为-1
同样可以赋值为0
但是对于-1和0之外的数不可以随意赋值 
例如赋值为0x3f3f3f3f 时需要写成 memset(a,0x3f,sizeof(a))
*/
int main()
{
    int a[10];
    int n;cin >> n;
    memset(a,n,sizeof(a));
    for(int i=0;i<10;i++) cout << a[i] << ' ';
    return 0;
}