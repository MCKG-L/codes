#include <iostream>
using namespace std;
/*
二分 + 贪心
*/
/*
7
3 1 2 1 8 5 6
*/
const int N = 1e5 + 10;
int n;
int a[N],q[N];
//q[i]表示最长子序列长度为i的最后一个元素的最小值 q一定是单调递增的
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int len = 0;
    q[0] = -2e9;
    for(int i=0;i<n;i++){
        //二分找到小于a[i]的最大值
        int l = 0,r = len;
        while(l < r){
            int mid = l + r + 1 >> 1;//尽量靠右
            if(q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len,r+1);
        q[r+1] = a[i];
    }
    cout << len << endl;
    return 0;
}