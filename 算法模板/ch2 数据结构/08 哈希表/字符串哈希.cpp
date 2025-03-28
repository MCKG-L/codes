#include <iostream>
using namespace std;
/*
字符串前缀哈希法：
字符串到数字的映射函数：将字母看作p进制数(A-1,B-2,C-3....Z-26)
然后按照p进制数的计算方法计算对应的值 最后mod Q
p取131或13331 q取2^64

计算前缀哈希的好处：可以快速的获得任意子串的哈希值
L~R字串的哈希值:  h[R] - h[L-1]*P^(R-L+1)

Q取2^64 可以简化处理：直接用无符号long long类型，其溢出机理自动实现mod2^64
*/

/*
典型例题：
给定一个长度为n的字符串，进行m次询问，每次给出l1,r1,l2,r2;
判断[l1,r1]和[l2,r2]区间的字符串字串是否完全相同
*/
const int N = 100010;
typedef unsigned long long ULL;
int n,m,P = 131;
char str[N];
ULL h[N],p[N];
ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
    cin >> n >> m >> str+1;
    p[0] = 1;//存储k次方的值
    for(int i=1;i<=n;i++){
        p[i] = p[i-1]*P;
        h[i] = h[i-1] * P + str[i];//字符串前缀哈希
    }
    while(m--){
        int l1,l2,r1,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(get(l1,r1) == get(l2,r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}