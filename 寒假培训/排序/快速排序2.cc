#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> vec;

void quick_sort(vector<int>& vec, int l, int r)
{
    if(l >= r) return;
    int x = vec[l], i = l - 1, j = r + 1;
    while(i < j)
    {
        do i++; while(vec[i] < x);
        do j--; while(vec[j] > x);
        if(i < j) swap(vec[i], vec[j]);
    }
    //最后j指向基准值
    quick_sort(vec, l, j);
    quick_sort(vec, j+1, r);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        vec.push_back(x);
    }
    random_shuffle(vec.begin(), vec.end());

    quick_sort(vec, 0, n-1);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
    
    
}