#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
思路：先按照区间的左端点排序，然后双指针，维护区间
最好用vector<pair<int,int>>
*/
const int N = 100010;
typedef pair<int,int> PII;
vector<PII> segs,res;
int n;
void merge(vector<PII> &segs){
    // vector<PII> res;
    sort(segs.begin(),segs.end());
    int st = -2e9,ed = -2e9;
    for(auto seg : segs){
        if(ed < seg.first){
            if(st != -2e9) res.push_back({st,ed});
            st = seg.first,ed = seg.second;
        }
        else ed = max(ed,seg.second);
    }
    if(st != -2e9) res.push_back({st,ed});
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout << res.size() << endl;
    for(int i=0;i<res.size();i++){
        cout << res[i].first << " " << res[i].second << endl;
    }

    return 0;
}