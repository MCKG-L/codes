#include <iostream>
using namespace std;
void search(int a[],int n,int x){
    int ans = -1;
    for(int i=0;i<n;i++){
        if(a[i] == x){
            ans = i;
            break;
        }
    }
    if(ans!=-1){
        cout << "index = " << ans;
    }else{
        cout << "Not found";
    }
}
int main()
{
    int n;cin >> n;
    int a[n] = {};
    for(int i=0;i<n;i++) cin >> a[i];
    int x;cin >> x;
    search(a,n,x);
    return 0;
}