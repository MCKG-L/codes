#include <iostream>
using namespace std;
/*
求滑动窗口内的最大值及最小值
*/
const int N = 100010;
int n,k;
int a[N],q[N];
int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    int hh = 0,tt = -1;
    //队列存储的是坐标
    for(int i=0;i<n;i++){
        //判断队头是否已经划出窗口
        if(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++ tt] = i;
        if(i >= k - 1) cout << a[q[hh]] << ' ';
    }
    puts("");
    hh = 0,tt = -1;
    for(int i=0;i<n;i++){
        //判断队头是否已经划出窗口
        if(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++ tt] = i;
        if(i >= k - 1) cout << a[q[hh]] << ' ';
    }
    puts("");
    return 0;
}