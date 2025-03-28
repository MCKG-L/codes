#include <iostream>
#include <map>
using namespace std;
const int N = 1e5+10;
int ans[N];
int n,k,s;

int main()
{
    cin >> n >> k >> s;
    while(s--){
        int a,b;
        cin >> a >> b;
        ans[a] += b;
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        if(ans[i] < k) res++;
    }
    cout << res << '\n';
    return 0;
}