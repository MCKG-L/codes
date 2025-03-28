#include <iostream>
using namespace std;
/*
并查集拓展1：维护集合中元素的数量

均通过根节点记录集合元素数量
*/
const int N = 100010;
int p[N];
int sz[N];
int n,m;
//返回x所属的根节点 + 路径压缩
int find(int x){
    //递归 路径压缩
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        p[i] = i;
        sz[i] = 1;
    }
    while(m--){
        char op[2];//读入字符串 会过滤空格换行
        int a,b; cin >> op;
        if(op[0] == 'C'){
            cin >> a >> b;
            if(find(a) == find(b)) continue;
            sz[find(b)] += sz[find(a)];
            p[find(a)] = find(b);
        }else if(op[1] == '1'){
            cin >> a >> b;
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }else{
            cin >> a;
            cout << sz[find(a)] << '\n';
        }
    }
    return 0;
}