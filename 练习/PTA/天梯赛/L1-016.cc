#include <iostream>
using namespace std;
int w[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char m[] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main()
{
    int cnt = 0;
    int t;cin >> t;
    while(t--){
        string s;cin >> s;
        int sum = 0;
        bool flag = true;
        for(int j=0;j<17;j++){
            if(s[j] >= '0' && s[j] <= '9'){
                sum += w[j]*(s[j]-'0');
            }else{
                flag = false;
                break;
            }
        }
        if(flag){
            if(m[sum%11] != s.back()){
                cnt++;
                cout << s << endl;
            }
        }else{
            cnt++;
            cout << s << endl;
        }
    }
    if(cnt == 0) cout << "All passed" << endl;
    return 0;
}