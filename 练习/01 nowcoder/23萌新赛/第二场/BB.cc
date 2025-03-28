#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10,M = N * 32;
//Trie树 存储每一个武器
int son[M][2],cnt[M],idx;//cnt记录每一个结点经过的数的个个数
int n,hp;
void insert(int x,int t){
    int p = 0;
    for(int i=30;i>=0;i--){
        int dx = x >> i & 1;
        if(!son[p][dx]) son[p][dx] = ++ idx;
        p = son[p][dx];
        cnt[p] += t;
    }
}
int find(int x,int h){
    int ans = 0,p = 0;
    for(int i=30;i>=0;i--){
        int dx = x >> i & 1;
        int dh = h >> i & 1;
        if(dh == 0){
            ans += cnt[son[p][dx^1]];
            p = son[p][dx];
        }else{
            p = son[p][dx^1];
        }
        //这里p可能为0 说明不存在合理的子节点
        //如果idx从0开始，应该直接break掉，否则相当于从根节点继续向下搜，明显不对
        //如果idx从1开始则不需要考虑，因为cnt[0] == 0
        if(p == 0) break;
    }
    return ans;
}
int main()
{
    cin >> n >> hp;
    while(n--){
        int op;cin >> op;
        if(op == 0){
            int x;cin >> x;
            insert(x,1);
        }else if(op == 1){
            int x;cin >> x;
            insert(x,-1);
        }else{
            int x,h;
            cin >> x >> h;
            int res = find(x,h);
            cout << res << endl;
            if(!res) hp --;
        }
    }
    cout << hp << endl;
    return 0;
}