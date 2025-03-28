#include <iostream>
using namespace std;
int cnt1[130],cnt2[130];
int main()
{
    for(int i=0;i<130;i++){
        cnt1[i] = 0;
        cnt2[i] = 100000;
    }
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        cnt1[s[i]]++;
        cnt2[s[i]] = cnt2[s[i]] == 100000 ? 1 : cnt2[s[i]] + 1;
    }
    int max_n = 1;
    int min_n = 100000;
    for(int i=0;i<130;i++){
        if(cnt1[i] > max_n) max_n = cnt1[i];
    }
    for(int i=0;i<130;i++){
        if(cnt2[i] < min_n) min_n = cnt2[i]; 
    }
    cout << max_n << ' ' << min_n << endl;
    return 0;
}