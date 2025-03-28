#include <iostream>
using namespace std;
void print_Binary(int x){
    int n = sizeof(x) * 8;
    for(int i=n-1;i>=0;i--){
        cout << (x >> i & 1);
    }
}
void func(int x){
    if(x > 0){
        func(x/2);
        cout << x % 2;
    }
}
int lowbit(int x){
    return x & -x;
}
//输出一个整数的二进制形式中1的个数
int __builtin(int n){
    int ans = 0;
    while(n) n -= lowbit(n),ans++;
    return ans;
}
int main()
{
    int n;cin >> n;
    func(n);
    cout << endl;
    print_Binary(n);
    cout << endl;
    func(lowbit(n));
    cout << endl;
    cout << __builtin(n);
    return 0;
}