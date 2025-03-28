#include <iostream>
#include <vector>
using namespace std;
const int N = 4,M = 1e4;
vector<int> A;
vector<int> add(vector<int> &A,vector<int> &B){
    vector<int> C;
    int t = 0;//进位
    for(int i=0;i<A.size()||i<B.size();i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % M);
        t /= M;
    }
    if(t) C.push_back(t);
    return C;
}
vector<int> mul(vector<int> &A,int b){
    vector<int> C;
    int t = 0;
    for(int i=0;i<A.size() || t;i++){
        if(i < A.size()) t += A[i]*b;
        C.push_back(t % M);
        t /= M;
    }
    //去掉前导0
    while(C.size()>1 && C.back() == 0) C.pop_back();
    return C;
}
vector<int> fac(int n){
    vector<int> p;
    p.push_back(1);
    for(int i=1;i<=n;i++){
        p = mul(p,i);
    }
    return p;
}
void out(vector<int> a){
    cout << a.back();
    for(int i=a.size()-2;i>=0;i--) printf("%04d",a[i]);
    cout << endl;
}
int main()
{
    A.push_back(0);
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        vector<int> s = fac(i);
        A = add(A,s);
    }
    // cout << A.size() << endl;
    // for(int i=A.size()-1;i>=0;i--) cout << A[i];
    out(A);
    return 0;
}