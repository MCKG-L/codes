#include <iostream>
using namespace std;
const int N = 2e7 + 10;
int cnt2[N],cnt5[N];
struct Node{
    int x2,x5;
}p[N];
int main()
{
    for(int i=1;i<=N;i++){
        if(i % 2 == 0){
            cnt2[i] = cnt2[i>>1]+1;
        }
        if(i % 5 == 0){
            cnt5[i] = cnt5[i/5]+1;
        }
    }
    p[1] = {0,0};
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        int sum_2 = 0,sum_5 = 0;
        sum_2 += cnt2[4*i-2];
        sum_5 += cnt5[4*i-2];
        sum_2 -= cnt2[i+1];
        sum_5 -= cnt5[i+1];
        p[i] = p[i-1];
        p[i].x2 += sum_2;
        p[i].x5 += sum_5;
    }
    int sum_2 = 0,sum_5 = 0;
    for(int i=1;i<=n;i++){
        sum_2 += p[i].x2;
        sum_5 += p[i].x5;
    }
    cout << min(sum_2,sum_5) << endl;
    return 0;
}