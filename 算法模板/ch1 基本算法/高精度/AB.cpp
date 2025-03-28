#include <iostream>
#include <vector>
using namespace std;
/*
高精度 X 高精度
*/
// vector<int> add(vector<int> &A,vector<int> &B){
//     vector<int> C;
//     int t = 0;//进位
//     for(int i=0;i<A.size()||i<B.size();i++){
//         if(i < A.size()) t += A[i];
//         if(i < B.size()) t += B[i];
//         C.push_back(t % 10);
//         t /= 10;
//     }
//     if(t) C.push_back(1);
//     return C;
// }
// vector<int> multi(vector<int> &A,vector<int> &B){
//     vector<int> C;
//     for(int i=0;i<A.size();i++){
//         vector<int> P(i);//后导0，错位相加
//         int t = 0;
//         for(int j=0;j<B.size() || t;j++){
//             if(j < B.size()) t += A[i]*B[j];
//             P.push_back(t % 10);
//             t /= 10;
//         }
//         C = add(C,P);
//     }
//     while(C.size() > 1 && C.back() == 0) C.pop_back();
//     return C;
// }

vector<int> add(vector<int> &A,vector<int> &B){
    vector<int> C;
    for(int i=0,t=0;i<A.size()||i<B.size()||t;i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}
vector<int> multi(vector<int> &A,vector<int> &B){
    vector<int> C;
    for(int i=0;i<A.size();i++){
        vector<int> P(i);
        for(int j=0,t=0;j<B.size()||t;j++){
            if(j < B.size()) t += A[i] * B[j];
            P.push_back(t % 10);
            t /= 10;
        }
        C = add(C,P);
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
int main()
{
    string a,b;
    cin >> a >> b;
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');

    vector<int> C = multi(A,B);
    for(int i=C.size()-1;i>=0;i--) cout << C[i];
    return 0;
}