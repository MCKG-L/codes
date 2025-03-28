#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> Q(n,vector<int>(m,0)),K,V,B;
    K = Q;V = Q;B = Q;
    for(int t=0;t<3;t++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(t == 0) cin >> Q[i][j];
                if(t == 1) cin >> K[i][j];
                if(t == 2) cin >> V[i][j];
            }
        }
    }
    vector<int> W(n);
    for(int i=0;i<n;i++) cin >> W[i];
    vector<vector<int>> A(m,vector<int>(m,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                A[i][j] += K[k][i] * V[k][j];
            }
        }
    }
    for(int k=0;k<m;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                B[i][j] += Q[i][k] * A[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << B[i][j]*W[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}