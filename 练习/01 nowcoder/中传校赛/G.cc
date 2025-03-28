#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
struct node{
    double p;
    int r,id;
//    bool operator< (const node &p1){
//    	return p1.r < r;
//	}
}a[N];
int p[N];
int n,m,q,s,k;
bool cmp(node p1,node p2){
    // return p1.r < p2.r;
    if(p1.r != p2.r) return p1.r < p2.r;
    else if(p1.p != p2.p) return p1.p > p2.p;
    else return p1.id < p2.id;
}
int m_binary(int n,int x){
	int l = 0,r = n - 1;
	while(l < r){
		int mid = l + r >> 1;
		if(a[mid].r >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}
//bool operator < (const node &p1,const node &p2){
//    return p1.r < p2.r;
//}
int find_k(int l,int r,int k){
    if(l == r) return p[l];
    int x = p[l],i = l - 1,j = r + 1;
    while(i < j){
        do i++;while(p[i] < x);
        do j--;while(p[j] > x);
        if(i < j) swap(p[i],p[j]);
    }
    int s = j - l + 1;
    if(k <= s) return find_k(l,j,k);

    return find_k(j+1,r,k-s);
}
int main()
{
    cin >> n >> m >> q;
    for(int i=0;i<n;i++){
        cin >> a[i].p >> a[i].r;
        a[i].id = i;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<m;i++){
        cin >> p[i];
    }
    sort(p,p+m);
    while(q--){
    cin >> s >> k;
    int mask = find_k(0,m-1,m-k);
//    int pos = lower_bound(a,a+n,mask,cmp) - a;
	int pos = m_binary(n,mask);
    if(pos == n){
        cout << -1 << endl;return 0;
    }
    pair<int,int> ans({a[pos].id,a[pos].p});
    for(int i=pos;i<n;i++){
        if(a[i].p > ans.second) ans = {a[i].id,a[i].p};
        else if(a[i].p == ans.second){
            if(ans.first < i) ans = {a[i].id,a[i].p};
        }
    }
    cout << ans.first << endl;
    }
    return 0;
}