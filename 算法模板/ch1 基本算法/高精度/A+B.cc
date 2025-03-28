#include <iostream>
#include <vector>
using namespace std;
/*
A + B
将一个数的每一位存放在数组中 低位在前，高位在后
*/
vector<int> add(vector<int> &A,vector<int> &B){
    vector<int> C;
    int t = 0;//进位
    for(int i=0;i<A.size()||i<B.size();i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1);
    return C;
}
int main()
{
    string a,b;
    vector<int> A,B;
    cin >> a >> b;
    for(int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
    }
    for(int i=b.size()-1;i>=0;i--){
        B.push_back(b[i]-'0');
    }
    vector<int> C = add(A,B);
    for(int i=C.size()-1;i>=0;i--){
        cout << C[i];
    }
    return 0;
}