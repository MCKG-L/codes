#include <bits/stdc++.h>
using namespace std;
/*
    跳马问题
    10*9的棋盘，一个马从(0,0)位置出发，经过k步刚好到达目标位置(x,y)
    问总共有多少种走法？
*/
//当前位置(x,y),目标位置(a,b),剩余步数rest
using ll = long long;
int a,b;//目标位置
ll dp[10][9][100];// x y rest
int dx[8] = {-2,-2,-1,1,2,2,1,-1};
int dy[8] = {-1,1,2,2,1,-1,-2,-2};
ll pick(int x,int y,int rest){
    if(x < 0 || x > 9 || y < 0 || y > 8){
        return 0;
    }
    return dp[x][y][rest];
}
ll solve(int a,int b,int k){
    dp[a][b][0] = 1;
    for(int rest=1;rest<=k;rest++){
        for(int x=0;x<10;x++){
            for(int y=0;y<9;y++){
                ll ans = 0;
                for(int i=0;i<8;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    ans += pick(nx,ny,rest-1);
                }
                dp[x][y][rest] = ans;
            }
        }
    }
    return dp[0][0][k];
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