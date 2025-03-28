#include <iostream>
#include <string.h>
#include <algorithm>
//复杂版本 存储了一对映射关系
using namespace std;
const int N = 100010;
int h[N],sz;
int ph[N],hp[N];
//ph[k]=i表示第k个插入的点的下标是i；hp[k]=i表示下标是k的点是第i个插入的
// int n,m;
void heap_swap(int a,int b){
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}
void up(int u){
    while(u / 2 > 0 && h[u/2] > h[u]){
        heap_swap(h[u/2],h[u]);
        u /= 2;
    }
}
void down(int u){
    int t = u;//t记录最小值
    if(u*2 <= sz && h[2*u] < h[t]) t = 2 * u;
    if(u*2+1 <= sz && h[2*u+1] < h[t]) t = 2*u + 1;
    if(u != t){
        heap_swap(h[u],h[t]);
        down(t);
    }
}
int main()
{
    int n,m=0;cin >> n;
    while(n--){
        char op[3];int k,x;
        cin >> op;
        if(!strcmp(op,"I")){
            cin >> x;
            sz++;m++;
            ph[m] = sz,hp[sz] = m;
            h[sz] = x;
            up(sz);
        }
        else if(!strcmp(op,"PM")) cout << h[1] << '\n';
        else if(!strcmp(op,"DM")){
            heap_swap(1,sz);
            sz--;down(1);
        }
        else if(!strcmp(op,"D")){
            cin >> k;
            k = ph[k];
            heap_swap(k,sz);sz--;
            down(k),up(k);
        }
        else{
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k),up(k);
        }
    }
    return 0;
}