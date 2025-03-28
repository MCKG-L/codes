#include <iostream>
#include <vector>
using namespace std;
const int N = 4,M = 1e4;
bool cmp(vector<int> &A,vector<int> &B){
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i=A.size()-1;i>=0;i--){
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}
//A-B
vector<int> sub(vector<int> &A,vector<int> &B){
    vector<int> C;
    for(int i=0,t=0;i<A.size();i++){
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t + M) % M);
        if(t < 0) t = 1;
        else t = 0;
        // int a = 0xfffffff;
    }
    //去掉前导0
    while(C.size()>1 && C.back() == 0) C.pop_back();
    return C;
}
void out(vector<int> a){
    cout << a.back();
    for(int i=a.size()-2;i>=0;i--){
        printf("%04d",a[i]);
    }
    cout << endl;
}
int main()
{
    string a,b;
    vector<int> A,B;
    cin >> a >> b;
    for(int i=a.size()-1;i>=0;i-=N){
        int st = max(0,i-N+1),len = i-st+1;
        A.push_back(stoi(a.substr(st,len)));
    }
    for(int i=b.size()-1;i>=0;i-=N){
        int st = max(0,i-N+1),len = i-st+1;
        B.push_back(stoi(b.substr(st,len)));
    }
    if(cmp(A,B)){//判断是否A大于等于B
        vector<int> C = sub(A,B);
       out(C);
    }else{
        vector<int> C = sub(B,A);
        cout << "-";
       out(C);
    }
    return 0;
}