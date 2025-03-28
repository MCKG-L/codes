#include <iostream>
using namespace std;
const int N = 110;
int a[N];
int n,d;
int main()
{
    cin >> n >> d;
    string s;
    while(n--){
        cin >> s;s = " " + s;
        for(int i=1;i<=d;i++){
            a[i] += (s[i] == 'x');
        }
    }
    int ans = 0,sum = 0;
    for(int i=1;i<=d;i++){
        if(!a[i]) sum ++;
        else{
            ans = max(ans,sum);
            sum = 0;
        }
    }
    ans = max(ans,sum);
    cout << ans << endl;
}