#include <bits/stdc++.h>
using namespace std;
const int N = 8,M = 1e8;
vector<int> add(vector<int> &A,vector<int> &B){
    int t = 0;
    vector<int> C;
    for(int i=0;i<A.size()||i<B.size()||t;i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % M);
        t /= M;
    }
    return C;
}
void out(vector<int> a){
    cout << a.back();
    for(int i=a.size()-2;i>=0;i--) printf("%08d",a[i]);
    cout << endl;
}
int main()
{
    string a,b;
    cin >> a >> b;
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i-=N){
        int st = max(0,i-N+1),len = i-st+1;
        A.push_back(stoi(a.substr(st,len)));
    }
    for(int i=b.size()-1;i>=0;i-=N){
        int st = max(0,i-N+1),len = i-st+1;
        B.push_back(stoi(b.substr(st,len)));
    }
    vector<int> C = add(A,B);
    out(C);
    return 0;
}