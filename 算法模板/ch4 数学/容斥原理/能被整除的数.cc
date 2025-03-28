#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
给定一个整数n和m个质数p1,p2,p3...pm
求1~n中能被p1,p2,p3...pm中至少一个数整除的整数有多少个
1 <= m <= 16
1 <=n,pi <= 1e9

思路：利用容斥原理，分别求出能被p1,p2,p3...pm整除的个数
再求出能同时被p1和p2、p2和p3 、、、整除的个数
...
直到求出能被p1*p2*p3*p4*...*pm整除的个数
利用容斥原理可以求出并集的元素个数

(S1US2US3U...USm) = S1+S2+...+Sm - (S1&S2+S2&S3+...+Sm-1&Sm) +...+(-1)^m-1*(S1&S2&..&Sm)
技巧：利用位运算来枚举所有的状态，1表示取，0表示不取
*/
typedef long long ll;
const int N = 20;
int n,m;
int p[N];
int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++) cin >> p[i];
    int ans = 0;
    for(int i=1;i<1 << m;i++){
        int t = 1,cnt = 0;//t表示p1*p2*..*pk
        //找到1的个数，即p[j]被选取的个数
        for(int j=0;j<m;j++){
            if(i >> j & 1){
                cnt++;
                if((ll)t * p[j] > n){
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        }
        if(t != -1){
            if(cnt % 2) ans += n / t;
            else ans -= n / t;
        }
    }
    cout << ans << endl;
    return 0;
}