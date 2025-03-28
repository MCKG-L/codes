/*
拉链法
*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100003;//最好取质数 冲突的概率最小
int h[N],e[N],ne[N],idx;
/*
1e-9 <= x <= 1e9 通过取模运算将x映射到一个具体的数，对应一个链表的结点
然后将x放到该节点下的链表中
查询某个数受否存在时，只需要找到这个数可能所在的链表，然后遍历这个链表找数

*/
void insert(int x){
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}
bool find(int x){
    int k = (x % N + N) % N;
    for(int i=h[k];i != -1;i = ne[i]){
        if(e[i] == x )return true;
    }
    return false;
}
int main()
{
    int n;cin >> n;
    memset(h,-1,sizeof(h));
    while(n--){
        char op;int x;
        cin >> op >> x;
        if(op == 'I') insert(x);
        else{
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}