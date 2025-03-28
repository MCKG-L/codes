/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>
using namespace std;
int main()
{
    srand(time(0));
    int mask = rand() % 900 + 100,t;
    vector<int> a;t = mask;
    while(mask) a.push_back(mask%10),mask/=10;
    int ans;
    // cout << "The lottery number is: " << t << endl;
    cout << "Enter a number with 3 digits: ";cin >> ans;
    int b[3],k=0;
    cout << "The lottery number is: " << t << endl;
    while(ans) b[k++] = ans%10,ans /= 10;
    if(a[0] == b[0] && a[1] == b[1] && a[2] == b[2]){
        cout << "Exact match: you win $10000" << endl;
        return 0;
    }
    int cnt = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<a.size();j++){
            if(b[i] == a[j]){
                cnt++;a[j] = -1;
                break;
            }
        }
    }
    if(cnt == 0)cout << "Sorry, no match" << endl;
    else if(cnt == 3) cout << "Match 3 digits: you win $3000" << endl;
    else if(cnt == 1 || cnt == 2) cout << "Match at least one digits:  you win $1000" << endl;
    return 0;
}
