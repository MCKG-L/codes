#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 1;
    int n;cin >> n;
    char a[n][n],b[n][n],s[n][n],c[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> s[i][j];
        }
    }
    bool mask = true;
    //1
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j] = a[n-1-j][i];
            if(b[i][j] != s[i][j]){
                mask = false;
            }
        }
    }
    if(mask){
        cout << ans;
        return 0;
    }else{
        ans++;
        mask = true;
    }
    //2
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j] = a[n-1-i][n-1-j];
            if(b[i][j]!=s[i][j]){
                mask = false;
            }
        }
    }
    if(mask){
        cout << ans;
        return 0;
    }else{
        ans++;
        mask = true;
    }
    //3
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j] = a[j][n-1-i];
            if(b[i][j]!=s[i][j]){
                mask = false;
            }
        }
    }
    if(mask){
        cout << ans;
        return 0;
    }else{
        ans++;
        mask = true;
    }
    //4
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j] = a[i][n-1-j];
            if(b[i][j]!=s[i][j]){
                mask = false;
            }
        }
    }
    if(mask){
        cout << ans;
        return 0;
    }else{
        ans++;
        mask = true;
    }
    //5-1
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j] = b[n-1-j][i];
            if(c[i][j] != s[i][j]){
                mask = false;
            }
        }
    }
    if(mask){
        cout << ans;
        return 0;
    }else{
        mask = true;
    }
    //5-2
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j] = b[n-1-i][n-1-j];
            if(c[i][j]!=s[i][j]){
                mask = false;
            }
        }
    }
    if(mask){
        cout << ans;
        return 0;
    }else{
        mask = true;
    }
    //5-3
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j] = b[j][n-1-i];
            if(c[i][j]!=s[i][j]){
                mask = false;
            }
        }
    }
    if(mask){
        cout << ans;
        return 0;
    }else{
        ans++;
        mask = true;
    }
    //6
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != s[i][j]){
                mask = false;
            }
        }
    }
    if(mask){
        cout << ans;
        return 0;
    }else{
        ans++;
        mask = true;
    }
    cout << ans;
    return 0;
}