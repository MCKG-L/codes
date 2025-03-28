#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int N = 10;
string a[N][N];
map<char,int> mp;
int n;
int num[N];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<n;i++){
        int cnt = 0;
        for(int j=1;j<n;j++){
            cnt += a[i][j].size() == 2;
        }
        num[i] = cnt;
        mp[a[0][i][0]] = cnt;
    }
    int p = n-1;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            int sum = num[i] + num[j];
            int s = 0;
            int l = a[i][j].size();
            for(int k=l-1;k>=0;k--){
                s += pow(p,l-k-1)*mp[a[i][j][k]];
            }
            if(s != sum){
                cout << "ERROR!" << endl;
                return 0;
            }
        }
    }
    for(int i=1;i<n;i++){
        cout << a[0][i]+'=' << num[i] << ' ';
    }
    cout << endl << p << endl;
    return 0;
}