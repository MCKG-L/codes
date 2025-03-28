#include <iostream>
using namespace std;
const int N = 10010,M = 100010;
int n,m;
char p[N],s[M];
int ne[N];
//KMP算法 O(N)
int main()
{
    cin >> n >> p + 1 >> m >> s + 1;
    //求next数组
    //next[i] = j的含义 使得p[1,j] == p[i-j+1,i]相等的j的最大值
    for(int i=2,j=0;i<=n;i++){
        while(j && p[i] != p[j+1]) j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }
    //KMP匹配
    for(int i=1,j=0;i<=m;i++){
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == n){
            cout << i - n << ' ';
            j = ne[j];//找下一个可能匹配成功的位置
        }
    }
    return 0;
}