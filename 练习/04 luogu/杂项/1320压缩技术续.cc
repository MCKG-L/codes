#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int ans=0,mask = 1,cnt = 0,n,sum=0;
    while(cin >> s){
        if(mask){
            cout << s.size() << " ";
            // ans = s[0]-'0'; 第一次ans必须为0，这样写有可能为1
            //压缩码的第二位可能为0表示第一行第一列为1
            mask = 0;
            n = s.size();
        }
        for(int i=0;i<s.size();i++){
            if(s[i]-'0' == ans){
                cnt++;
                sum++;
            }else{
                sum++;
                ans = ans == 0 ? 1 : 0;
                cout << cnt << " ";
                cnt = 1;
            }
            if(sum == n * n)cout << cnt;
        }
    }
    return 0;
}