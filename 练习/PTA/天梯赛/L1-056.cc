#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int m_find(vector<pair<string,int>> &p,double av){
    int l = 0,r = p.size()-1;
    while(l < r){
        int mid = l + r >> 1;
        if(p[mid].second >= av) r = mid;
        else l = mid + 1;
    }
    int ll = l;
    while(p[ll].second >= av) ll--;
    if(abs(p[l].second-av) > abs(p[ll].second-av)){
        return ll;
    }else return l;

}
int main()
{
    vector<pair<string,int>> p;
    int n;cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        string s;int a;
        cin >> s >> a;
        p.push_back(make_pair(s,a));
        sum += a;
    }
    sort(p.begin(),p.end(),
    [&](pair<string,int> p1,pair<string,int> p2){return p1.second < p2.second;});
    double av = 1.0*sum / n / 2;
    int l = m_find(p,av);
    cout << (int)av << ' ' << p[l].first << endl;
    return 0;
}