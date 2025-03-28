#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int presum[1000];
void preSum(vector<int> &a){
    int N = a.size();
    presum[0] = a[0];
    for(int i=1;i<N;i++){
        presum[i] = presum[i-1] + a[i];
    }
}
int rangeSum(int l,int r){
    return l == 0 ? presum[r] : presum[r] - presum[l-1];
}
int main()
{
    int n,x;cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        a.push_back(x);
    }
    preSum(a);
    cout << rangeSum(1,3);
    return 0;
}