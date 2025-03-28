#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    int min_ = 0,max_ = 1e9;
    while(n--){
        int a,b;
        cin >> a >> b;
        min_ = max(min_,a/(b+1)+1);
        max_ = min(max_,a/b);
    }
    cout << min_ << ' ' << max_ << endl;
    return 0;
}