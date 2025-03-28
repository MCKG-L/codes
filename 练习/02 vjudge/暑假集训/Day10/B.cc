#include <iostream>
#include <map>
using namespace std;
const int N = 110;
int a[N][N];
int s[N],p[N];
int n,m;
// map<int,int> mp;
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> p[i] >> s[i];
        for(int j=0;j<s[i];j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j || p[i] < p[j] || s[i] > s[j]) continue;
            map<int,int> mp;
            for(int k=0;k<s[j];k++) mp[a[j][k]]++;
            bool flag = false;
            for(int k=0;k<s[i];k++){
                if(!mp.count(a[i][k])){
                    flag  = true;
                    break;
                }
            }
            if(flag) continue;
            if(p[i] == p[j]){
                if(s[j] > s[i]){
                    cout << "Yes" << endl;
                    return 0;
                }else continue;
            }else{
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}