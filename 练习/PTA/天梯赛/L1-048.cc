#include <iostream>
using namespace std;
int main()
{
    int ra,rb,ca,cb;
    cin >> ra >> ca;
    int a[ra][ca];
    for(int i=0;i<ra;i++){
        for(int j=0;j<ca;j++){
            cin >> a[i][j];
        }
    }
    cin >> rb >> cb;
    int b[rb][cb];
    for(int i=0;i<rb;i++){
        for(int j=0;j<cb;j++){
            cin >> b[i][j];
        }
    }
    if(ca != rb){
        cout << "Error: " << ca << " != " << rb << endl;
        return 0;
    }
    int ans[ra][cb];
    for(int i=0;i<ra;i++){
        for(int j=0;j<cb;j++){
            int sum = 0;
            for(int k=0;k<ca;k++) sum += a[i][k]*b[k][j];
            ans[i][j] = sum;
        }
    }
    cout << ra << " " << cb << endl;
    for(int i=0;i<ra;i++){
        for(int j=0;j<cb;j++){
            cout << ans[i][j];
            if(j != cb-1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}