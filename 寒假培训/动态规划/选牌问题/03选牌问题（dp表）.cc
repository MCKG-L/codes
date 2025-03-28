#include <bits/stdc++.h>
using namespace std;
/*
13
5 7 4 5 8 1 6 0 3 4 6 1 7
*/
int arr[100];
int fm[100][100],gm[100][100];
void way2(int n){
    //base-case
    for(int i=0;i<n;i++){
        fm[i][i] = arr[i];
        gm[i][i] = 0;
    }
    //沿着对角线递推
    for(int startCol=1;startCol<n;startCol++){
        int l = 0;
        int r = startCol;
        while(r < n){
            fm[l][r] = max(arr[l]+gm[l+1][r],arr[r]+gm[l][r-1]);
            gm[l][r] = min(fm[l+1][r],fm[l][r-1]);
            l++;
            r++;
        }
    }
    int first = fm[0][n-1];
    int second = gm[0][n-1];
    cout << "arr: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " \n"[i == n-1];
    }
    cout << "fm: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%2d ",fm[i][j]);
        }
        cout << endl;
    }
    cout << "gm: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%2d ",gm[i][j]);
        }
        cout << endl;
    }
    cout << "先手：" << first << '\n';
    cout << "后手：" << second << '\n';
    cout << (first > second ? "先手" : "后手") << "赢!";
}
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    way2(n);
    return 0;
}