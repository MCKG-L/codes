#include <iostream>
#include <queue>
using namespace std;
/*

对顶堆：同时使用小根堆和大根堆的数据结构，用来动态维护第k大的数，可以用来求中位数，第k大的数，第k小的数等

实现原理：小根堆在上，大根堆在下，小根堆里的所有元素都不小于大根堆里的元素，维护小根堆的元素个数始终为k即可，取出的小根堆堆顶元素即为第k大的数
1、维护 当小根堆的元素数量小于k时，不断将大根堆的堆顶取出插入到小根堆中，直到小根堆的元素数目为k。当小根堆的元素数目大于k时，不断去除小根堆的堆顶元素插入到大根堆中
直到小根堆的元素数目为k

2、插入：若插入的元素大于或等于小根堆的堆顶元素，则将其插入小根堆，否则将其插入大根堆，然后维护对顶堆

3、查询：取出小根堆堆顶 即为第k大

4、删除：
*/
priority_queue<int> q1;//大根堆
priority_queue<int,vector<int>,greater<int>> q2;//小根堆
const int N = 1e5 + 10;
int a[N];
void solve(){
    int n,k;cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        q2.push(x);
        if(q2.size() > k){
            // q1.push(q2.top());
            q2.pop();
        }
    }
    cout << q2.top() << endl;
}
int main()
{
    // int n;cin >> n;
    // for(int i=1;i<=n;i++) cin >> a[i];
    // q1.push(a[1]);cout << a[1] << endl;
    // for(int i=2;i<=n;i++){
    //     int x = a[i];
    //     if(x > q1.top()) q2.push(x);
    //     else q1.push(x);
    //     if(q1.size() > q2.size() + 1){
    //         q2.push(q1.top());q1.pop();
    //     }else if(q2.size() > q1.size() + 1){
    //         q1.push(q2.top());q2.pop();
    //     }
    //     if(i & 1) cout << (q1.size()>q2.size()?q1.top():q2.top()) << endl;
    // }
    solve();
    return 0;
}