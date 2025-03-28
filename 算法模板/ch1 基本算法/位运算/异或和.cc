#include <iostream>
using namespace std;
/*
找到一堆数中出现次数为奇数的那个数，保证结果唯一，有严格的空间限制（4Mb）
异或运算：
k个相同的数求异或和，如果k为奇数则结果为k，如果k为偶数，结果为0
则一堆数中唯一的那个出现次数为奇数的数就是所有数的异或和
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int ans = 0;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
    return 0;
}