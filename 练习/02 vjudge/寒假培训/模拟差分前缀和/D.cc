#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int main()
{
    vector<int> a;
    int ans1[N][2],ans2[N][2];
    string s;
    int sum_a=0,sum_b=0;
    int sum_a2=0,sum_b2=0;
    int cnt1=0,cnt2=0;
    while(cin >> s){
        for(auto i=s.begin();i!=s.end();i++){
            if(*i=='W'){
                sum_a++;
                sum_a2++;
            }
            else if(*i=='L'){
                 sum_b++;
                 sum_b2++;
            }
            if(sum_a>=11&&fabs(sum_a-sum_b)>=2||sum_b>=11&&fabs(sum_a-sum_b)>=2||*i=='E'){
                ans1[cnt1][0] = sum_a;
                ans1[cnt1][1] = sum_b;
                cnt1++;
                sum_a = sum_b = 0;
            }
            if(sum_a2>=21&&fabs(sum_a2-sum_b2)>=2||sum_b2>=21&&fabs(sum_a2-sum_b2)>=2||*i=='E'){
                ans2[cnt2][0] = sum_a2;
                ans2[cnt2][1] = sum_b2;
                sum_a2 = sum_b2 = 0; 
                cnt2++;
            }
        }
    }
    for(int i=0;i<cnt1;i++){
        cout << ans1[i][0] << ":" << ans1[i][1] << endl;
    }
    cout << endl;
    for(int i=0;i<cnt2;i++){
        cout << ans2[i][0] << ":" << ans2[i][1] << "\n\0"[i==cnt2-1];
    }
    return 0;
}