#include <iostream>
#include <map>
using namespace std;
const int N = 1e5+10;
bool st[N];
int a[N];
int main()
{
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int ans = n;
    for(int i=1;i<=n;i++){
        if(!st[i]){
            ans--;
            for(int j=i;!st[j];j=a[j]){
                st[j] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}