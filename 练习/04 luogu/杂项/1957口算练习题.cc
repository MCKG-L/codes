#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int n;cin >> n;
    int cnt = 0;
    while(cnt++ < n){
        int cnt1 = 0;
        string s1,s2;
        char mask;
        while(cnt1 < 2){
            string s;
            cin >> s;
            if(s == "a" || s == "b" || s == "c"){
                mask = s[0];
            }else{
                if(cnt1 == 0){
                    s1 = s;
                    cnt1++;
                }else{
                    s2 = s;
                    cnt1++;
                }
            }
        }
        int num1=0,num2=0;
        for(int i=s1.size()-1;i>=0;i--){
            num1 += (s1[i]-'0')*pow(10,s1.size()-1-i);
        }
        for(int i=s2.size()-1;i>=0;i--){
            num2 += (s2[i]-'0')*pow(10,s2.size()-1-i);
        }
        if(mask == 'a'){
            int d = num1 + num2;
            int cnt2 = 0;
            if(d <= 0){
                cnt2++;
                d *= -1;
            }
            while(d!=0){
                d /= 10;
                cnt2++;
            }
            string ss;
            ss += s1 + "+" + s2 + "=";
            cout << ss << num1+num2 << '\n' << ss.size()+cnt2 << '\n';
        }else if(mask == 'b'){
            int d = num1 - num2;
            int cnt2 = 0;
            if(d <= 0){
                cnt2++;
                d *= -1;
            }
            while(d!=0){
                d /= 10;
                cnt2++;
            }
            string ss;
            ss += s1 + "-" + s2 + "=";
            cout << ss << num1-num2 << '\n' << ss.size()+cnt2 << '\n';
        }else if(mask == 'c'){
            int d = num1 * num2;
            int cnt2 = 0;
            if(d <= 0){
                cnt2++;
                d *= -1;
            }
            while(d!=0){
                d /= 10;
                cnt2++;
            }
            string ss;
            ss += s1 + "*" + s2 + "=";
            cout << ss << num1*num2 << '\n' << ss.size()+cnt2 << '\n';
        }
    }
    return 0;
}