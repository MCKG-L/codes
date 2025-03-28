#include <iostream>
#include <cstring>
using namespace std;
//dp
const int N = 100010;
int l[N],r[N],g[10];
int f[N];//表示以第i个数结尾的最长接龙数列
int ans,n;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        char num[10];
        scanf("%s",num);
        l[i] = num[0]-'0',r[i] = num[strlen(num)-1]-'0';
    }
    for(int i=0;i<n;i++){
        f[i] = 1;
        f[i] = max(f[i],g[l[i]]+1);
        g[r[i]] = max(g[r[i]],f[i]);
        ans = max(ans,f[i]);
    }
    for(int i=0;i<10;i++){
        cout << g[i] << ' ';
    }
    cout << endl;
    cout << n - ans << endl;
    return 0;
}