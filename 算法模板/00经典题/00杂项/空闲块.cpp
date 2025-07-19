#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;
/* acwing P5073 北京航空航天大学机试题
在操作系统中，空闲存储空间通常以空闲块链表方式组织，每个块包含块起始位置、块长度及一个指向下一块的指针。
空闲块按照存储位置升序组织，最后一块指向第一块（构成循环链表）。
1、从当前位置开始遍历空闲块链表（初始是从地址最小的第一个空闲块开始），寻找满足条件的最小块（即：大于等于请求空间的最小空闲块，如果有多个大小相同的最小空闲块，则选择遍历遇到的第一个最小空闲块）（最佳适应原则）；
2、如果选择的空闲块恰好与请求的大小相符合，则将它从链表中移除并返回给用户；这时当前位置变为移除的空闲块指向的下一空闲块；
3、如果选择的空闲块大于所申请的空间大小，则将大小合适的空闲块返回给用户，剩下的部分留在空闲块链表中，且剩下位置的起始地址不变；这时当前位置仍然为该空闲块；
4、如果找不到足够大的空闲块，则申请失败；这时当前位置不变。
按照上述原则模拟完空闲空间申请后，输出当前空闲空间链表状态，即从当前位置开始，遍历链表，分行输出剩余空闲块的起始位置和长度，位置和长度之间以一个空格分隔。
若申请完后，链表中没有空闲块，则什么都不输出。
*/
void solve(){
    int n;cin >> n;
    vector<array<int,2>> a(n);
    vector<int> nex(n),pre(n);
    for(int i=0;i<n;i++){
        nex[i] = (i + 1) % n;
        pre[i] = (i - 1 + n) % n;
        int sta,len;
        cin >> sta >> len;
        a[i] = {sta,len};
    }
    int x;
    int now = 0,empty = 0;
    while(cin >> x){
        if(x == -1) break;
        if(empty == 1) continue;
        int ver = -1;
        int p = now,Min = inf,f = 1;
        while(f || p != now){
            f = 0;
            if(a[p][1] >= x){
                if(a[p][1] < Min){
                    Min = a[p][1];
                    ver = p;
                }
            }
            p = nex[p];
        }
        if(~ver){
            if(Min == x){
                int prev = pre[ver],next = nex[ver];
                pre[next] = prev;
                nex[prev] = next;
                if(next != prev) now = next;
                else{
                    empty = 1;
                }
            }else{
                a[ver][1] -= x;
                now = ver;
            }
        }
    }
    int p = now;
    int f = 1;
    while(!empty && (f || p != now)){
        f = 0;
        cout << a[p][0] << ' ' << a[p][1] << endl;
        p = nex[p];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}
