#include <bits/stdc++.h>
using namespace std;
/*
13
5 7 4 5 8 1 6 0 3 4 6 1 7
*/
int arr[100];
int fm[100][100],gm[100][100];
int f(int l,int r);
int g(int l,int r);//声明
//先手函数
int f(int l,int r){
    if(fm[l][r] != -1) return fm[l][r];
    int ans = 0;
    if(l == r) ans = arr[l];
    else{
        int p1 = arr[l] + g(l+1,r);
        int p2 = arr[r] + g(l,r-1);
        ans = max(p1,p2);
    }
    fm[l][r] = ans;
    return ans;
}
//后手函数
int g(int l,int r){
    if(gm[l][r] != -1) return gm[l][r];
    int ans = 0;
    if(l == r) ans = 0;
    else{
        int p1 = f(l+1,r);//对方拿走最左边纸牌
        int p2 = f(l,r-1);//对方拿走最右边纸牌
        ans = min(p1,p2);//对方绝对聪明，只会给你最小值
    }
    gm[l][r] = ans;
    return ans;
}
void way2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fm[i][j] = -1;
            gm[i][j] = -1;
        }
    }
    // //base-case
    // for(int i=0;i<n;i++){
    //     fm[i][i] = arr[i];
    //     gm[i][i] = 0;
    // }
    // //沿着对角线递推
    // for(int startCol=1;startCol<n;startCol++){
    //     int l = 0;
    //     int r = startCol;
    //     while(r < n){
    //         fm[l][r] = max(arr[l]+gm[l+1][r],arr[r]+gm[l][r-1]);
    //         gm[l][r] = min(fm[l+1][r],fm[l][r-1]);
    //         l++;
    //         r++;
    //     }
    // }
    int first = f(0,n-1);
    int second = g(0,n-1);
    cout << "fm: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%2d ",fm[i][j]);
        }
        cout << endl;
    }
    cout << "gm: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%2d ",gm[i][j]);
        }
        cout << endl;
    }
    cout << "先手：" << first << '\n';
    cout << "后手：" << second << '\n';
    cout << (first > second ? "先手" : "后手") << "赢";
}
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    way2(n);
    return 0;
}