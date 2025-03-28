#include <bits/stdc++.h>
using namespace std;
int process1(int cur,int rest,int aim,int N){
    if(rest == 0){
        return cur == aim ? 1 : 0;
    }
    //rest > 0
    if(cur == 1) return process1(cur+1,rest-1,aim,N);
    if(cur == N) return process1(cur-1,rest-1,aim,N);
    return process1(cur+1,rest-1,aim,N) + process1(cur-1,rest-1,aim,N);
}
int dp1[100][100];
int process2(int cur,int rest,int aim,int N){
    if(dp1[cur][rest]!=-1) return dp1[cur][rest];
    int ans = 0;
    if(rest == 0){
        ans = cur == aim ? 1 : 0;
    }else if(cur == 1){
        ans = process2(cur+1,rest-1,aim,N);
    }else if(cur == N){
        ans = process2(cur-1,rest-1,aim,N);
    }else{
        ans = process2(cur+1,rest-1,aim,N) + process2(cur-1,rest-1,aim,N);
    }
    dp1[cur][rest] = ans;
    return ans;
}
//暴力递归
int way1(int N,int start,int aim,int k){
    return process1(start,k,aim,N);
}
//加入缓存表
int way2(int N,int start,int aim,int k){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=k;j++){
            dp1[i][j] = -1;
        }
    }
    return process2(start,k,aim,N);
}
//直接构造dp表
int dp2[100][100];
int way3(int N,int start,int aim,int k){
    dp2[aim][0] = 1;
    for(int rest=1;rest<=k;rest++){
        dp2[1][rest] = dp2[2][rest-1];
        for(int cur=2;cur<N;cur++){
            dp2[cur][rest] = dp2[cur-1][rest-1] + dp2[cur+1][rest-1];
        }
        dp2[N][rest] = dp2[N-1][rest-1];
    }
    // for(int rest=1;rest<=k;rest++){
    //     for(int cur=1;cur<=N;cur++){
    //         if(cur == 1) dp2[cur][rest] = dp2[cur+1][rest-1];
    //         else if(cur == N) dp2[cur][rest] = dp2[cur-1][rest-1];
    //         else dp2[cur][rest] = dp2[cur-1][rest-1] + dp2[cur+1][rest-1];
    //     }
    // }
    cout << "dp表: \n";
    for(int i=0;i<=N;i++){
        for(int j=0;j<=k;j++){
            cout << dp2[i][j] << " \n"[j == k];
        }
    }
    cout << "ans: ";
    return dp2[start][k];
}
int main()
{
    int N,start,aim,k;
    cin >> N >> start >> aim >> k;
    cout << way3(N,start,aim,k);
    return 0;
}