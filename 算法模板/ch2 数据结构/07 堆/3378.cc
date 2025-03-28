#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int h[N],sz;
void up(int u){
    while(u / 2 > 0 && h[u/2] > h[u]){
        swap(h[u/2],h[u]);
        u /= 2;
    }
}
void down(int u){
    int t = u;//t记录最小值下标
    if(u*2 <= sz && h[2*u] < h[t]) t = 2 * u;
    if(u*2+1 <= sz && h[2*u+1] < h[t]) t = 2*u + 1;
    if(u != t){
        swap(h[u],h[t]);
        down(t);
    }
}
void insert(int x){
    h[++sz] = x;
    up(sz);
}
void del(){
    h[1] = h[sz];
    sz--;down(1);
}
int main()
{
    int n;cin >> n;
    while(n--){
        int op,x;
        cin >> op;
        if(op == 1){
            cin >> x;
            insert(x);
        }else if(op == 2){
            cout << h[1] << '\n';
        }else if(op == 3){
            del();
        }
    }
    return 0;
}