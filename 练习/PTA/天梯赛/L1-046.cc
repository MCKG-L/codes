#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> div(vector<int> &A,int x,int &r){
    vector<int> C;
    r = 0;
    for(int i=A.size()-1;i>=0;i--){
        r = r * 10 + A[i];
        C.push_back(r/x);
        r %= x;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1 && C.back() == 0) C.pop_back();
    return C;
}
int main()
{
    int x,i=1;
    cin >> x;
    while(1){
        vector<int> A(i,1);int r;
        vector<int> C = div(A,x,r);
        if(r == 0){
            for(int j=C.size()-1;j>=0;j--){
                cout << C[j];
            }
            cout << " " << i << endl;
            break;
        }
        i++;
    }
    return 0;
}