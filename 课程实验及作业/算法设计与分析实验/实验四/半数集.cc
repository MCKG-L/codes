#include <iostream>
using namespace std;
int cnt;
void dfs(int x){
    cnt ++;
    for(int i=1;i<=x/2;i++){
        dfs(i);
    }
}
int main()
{
    int n;cin >> n;
    dfs(n);
    cout << cnt << endl;
    return 0;
}