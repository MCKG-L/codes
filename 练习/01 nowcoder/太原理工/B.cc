#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 15;
pair<char,char> p[N];
bool cmp(pair<char,char> p1,pair<char,char> p2){
    if(p1.second != p2.second) return p1.second < p2.second;
    return p1.first < p2.first;
}
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        char s[3];
        scanf("%s",s);
        p[i] = {s[0],s[1]};
    }
    // for(int i=0;i<n;i++){
    //     cout << p[i].first << ' ' << p[i].second << endl;
    // }
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++){
        cout << p[i].first << p[i].second << ' ';
    }
    return 0;
}