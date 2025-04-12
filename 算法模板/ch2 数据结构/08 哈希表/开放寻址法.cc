//开放寻址法
#include <iostream>
#include <cstring>
using namespace std;
/*
存在hash冲突，根据冲突的解决方法 分为开放寻址法和拉链法
*/
const int N = 200003,null = 0x3f3f3f3f;
//h[k] == null 表明k位置没有元素    
int h[N];
int find(int x){
    //如果x存在，返回x的位置，如果不存在返回应该在的位置
    int k = (x % N + N) % N;
    while(h[k] != null && h[k] != x){
        k++;
        if(k == N) k = 0;
    }
    return k;
}

int main()
{
    int n;cin >> n;
    memset(h,0x3f,sizeof(h));
    while(n--){
        char op;int x;
        cin >> op >> x;
        int k = find(x);
        if(op == 'I'){
            h[k] = x;
        }else{
            if(h[k] != null) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}