#include <iostream>
#include <algorithm>
using namespace std;
/*
堆的存储：用一个一维数组存储，下标从1开始，若父节点为x(下标)，
则左子结点下标为2x，右子节点下标为2x+1

基本操作：
down(k):不断地和其左子节点和右子节点(可能不存在)比较，如果大于子节点，交换二者的值

up(k):不断的和其父节点比较，如果小于父节点，交换二者的值
操作：

1、插入一个数：heap[++size] = x;up(size);
2、求集合中的最小值：heap[1]
3、删除最小值：heap[1] = heap[size];size--;down(1);
4、删除任意一个元素：heap[k] = heap[size];size--;down(k);up(k);
5、修改任意一个元素：heap[k] = x;down(k);up(k);
*/

//时间复杂度：建堆 O(N)，排序重建O(NlgN),堆排序总时间复杂度：O(NlgN);
const int N = 100010;
int n,m;
int h[N],siz;
void up(int u){
    while(u / 2 > 0 && h[u/2] > h[u]){
        swap(h[u/2],h[u]);
        u /= 2;
    }
}
void down(int u){
    int t = u;//t记录最小值
    if(u*2 <= siz && h[2*u] < h[t]) t = 2 * u;
    if(u*2+1 <= siz && h[2*u+1] < h[t]) t = 2*u + 1;
    if(u != t){
        swap(h[u],h[t]);
        down(t);
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> h[i];
    siz = n;
    for(int i=n/2;i>0;i--) down(i);
    while(m--){
        cout << h[1] << ' ';
        h[1] = h[siz];
        siz--;down(1);
    }
}