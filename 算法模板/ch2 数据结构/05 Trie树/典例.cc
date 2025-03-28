#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10,M = N * 32;
/*
利用Trie树存储一些数，支持添加和删除操作
询问时得到 这些数中和给定值x的异或值大于h的数的个数
*/
//Trie树 存储每一个武器
int son[M][2],cnt[M],idx;//cnt记录每一个结点经过的数的个数
int n,hp;
void insert(int x,int t){
    int p = 0;
    for(int i=30;i>=0;i--){
        int dx = x >> i & 1;
        if(!son[p][dx]) son[p][dx] = ++ idx;
        p = son[p][dx];
        cnt[p] += t;//标记每个结点经过的数的个数 添加则+1，删除即为-1
    }
}
int find(int x,int h){
    int ans = 0,p = 0;//从根节点开始搜索
    for(int i=30;i>=0;i--){
        int dx = x >> i & 1;
        int dh = h >> i & 1;
        if(dh == 0){
        /*
        如果h的当前位是0，则在该位上和x的异或值为1的所有数都满足 最后异或值大于h
        cnt[p]表示 经过p结点的所有数的个数
        */
            ans += cnt[son[p][dx^1]];//该位和x异或值为1的个数
            p = son[p][dx];//继续搜索该为异或值为0的数，后续可能得到的异或值大于h
        }else{
            //h的当前位是1，则只能在该位和x异或的1的数中搜索，其他情况一定不满足条件
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