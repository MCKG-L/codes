#include <bits/stdc++.h>
using namespace std;
/*
    跳马问题
    10*9的棋盘，一个马从(0,0)位置出发，经过k步刚好到达目标位置(x,y)
    问总共有多少种走法？
*/
//当前位置(x,y),目标位置(a,b),剩余步数rest
int a,b;//目标位置
int process(int x,int y,int rest){
    if(x < 0 || x > 9 || y < 0 || y > 8){
        return 0;
    }
    if(rest == 0){
        return x == a && y == b;
    }

    int ans = process(x-2,y-1,rest-1);
    ans += process(x-2,y+1,rest-1);
    ans += process(x-1,y+2,rest-1);
    ans += process(x+1,y+2,rest-1);
    ans += process(x+2,y+1,rest-1);
    ans += process(x+2,y-1,rest-1);
    ans += process(x+1,y-2,rest-1);
    ans += process(x-1,y-2,rest-1);
    return ans;
}
int solve(int a,int b,int k){
    return process(0,0,k);
}
int main()
{
    int k;
    clock_t start,end;
    cin >> a >> b >> k;
    start = clock();
    cout << "ans: " << solve(a,b,k) << endl;
    end = clock();
    cout << "time : " << double(end - start)/CLOCKS_PER_SEC << "s";
    return 0;
}