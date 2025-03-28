/*
贝茜是一头饥饿的牛。
每天晚上，如果牛棚中还有干草的话，贝茜都会吃掉其中的一捆。初始时，牛棚中没有干草。为了让贝茜不被饿死，农夫约翰制定了 N个给贝茜送干草的计划。
其中第 i个计划是在第 di 天的白天给贝茜送去 bi捆干草。
这些计划互不冲突，保证 1≤d1<d2<…<dN≤T
请你计算，贝茜在第 1∼T
天中有多少天有干草吃。
*/
#include <iostream>
using namespace std;
typedef long long ll;
ll T,N;
int main()
{
    cin >> N >> T;
    ll last = 0,cnt = 0,len = 0,ans = 0;
    //每次考虑 (last,d)的区间
    //last上一次考虑到的位置 cnt当前的草数 len当前区间中能吃到草的天数 
    for(int i=0;i<N;i++){
        ll d,b;
        cin >> d >> b;
        len = min(d - last - 1,cnt);
        last = d - 1;
        cnt += b - len;
        ans += len;
    }
    ans += min(T-last,cnt);
    cout << ans << endl;
    return 0;
}