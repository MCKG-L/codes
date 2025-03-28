#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M = 100;
    bool ok = 1;
    for(int i=1;i<=M;i++){
        system("makedata.exe in.txt");
        system("1.exe in.txt out1.txt");
        system("2.exe in.txt out2.txt");
        if(system("fc out1.txt out2.txt")){
            ok = 0;
            cout << "出现错误" << endl;
            break;
        }
    }
    if(ok){
        cout << "没有差异！" << endl;
    }else{
        freopen("in.txt","r",stdin);
        cout << "错误数据是：" << endl;
        int x;
        while(cin >> x) cout << x << endl;
    }
    return 0;
}