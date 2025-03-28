#include <iostream>
#include <vector>
using namespace std;
int cnt[105];
int main()
{
    int n;cin >> n; vector<vector<int>> a(n);
    for(int i=0;i<n;i++) cin >> cnt[i],cnt[i] *= 10;
    int prev = -1,k = 1;
    while(1){
        bool mask = 0;
        for(int i=0;i<n;i++){
            if(prev == i) k++;
            if(cnt[i] > 0){
                a[i].push_back(k);
                cnt[i]--,mask = 1;
                prev = i,k++;
            }
        }
        if(!mask) break;
    }
    for(int i=0;i<n;i++){
        cout << '#' << i + 1 << "\n";
        for(unsigned int j=0;j<a[i].size();j++){
            cout << a[i][j];
            if((j + 1) % 10 == 0) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}