#include <bits/stdc++.h>
using namespace std;
/*
题目描述：
有N张纸牌，分别对应一个值，两个人玩，每一次只能拿走最左边的纸牌或者最右边的纸牌
两个人都是绝对聪明（考虑全局）
问 先手赢还是后手赢，并输出各自的总分数

[50,100,20,10]
先手：10 100
后手：50 20
*/
int f(int l,int r);
int g(int l,int r);//声明
int arr[100];
//先手函数
int f(int l,int r){
    if(l == r) return arr[l];
    int p1 = arr[l] + g(l+1,r);
    int p2 = arr[r] + g(l,r-1);
    return max(p1,p2);
}
//后手函数
int g(int l,int r){
    if(l == r) return 0;
    int p1 = f(l+1,r);//对方拿走最左边纸牌
    int p2 = f(l,r-1);//对方拿走最右边纸牌
    return min(p1,p2);//对方绝对聪明，只会给你最小值
}
void way1(int n){
    int first = f(0,n-1);
    int second = g(0,n-1);
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
    way1(n);
}