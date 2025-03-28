#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    string s;cin >> s;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'K'){
            if(i - 1 < 0) continue;
            else if(s[i-1] == 'V') ans++;
        }
    }
    int ans2 = 0;
    for(int i=0;i<n;i++){
        s[i] = s[i]=='K' ? 'V' : 'K';
        int sum = 0;
        for(int j=0;j<n;j++){
            if(s[j] == 'K'){
                if(j-1 < 0) continue;
                else if(s[j-1] == 'V') sum++;
            }
        }
        ans2 = max(ans2,sum);
        s[i] = s[i] == 'K' ? 'V' : 'K';
    }
    cout << max(ans,ans2) << endl;
    return 0;
}