#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int N = 10010;
int a[N],n;
void insert_sort(){
    for(int i=1;i<n;i++){
        int x = a[i];
        int j = i - 1;
        while(j != -1 && x < a[j]){
            a[j+1] = a[j];
            j --;
        }
        a[j+1] = x;
    }
}
int main()
{
    // cout << "请输入数据： " << endl;
    // cin >> n;
    srand(time(NULL));
    n = rand() % 12 + 1;
    // for(int i=0;i<n;i++) cin >> a[i];
    srand(0);
    for(int i=0;i<n;i++) a[i] = rand() % 10 + 1;
    for(int i=0;i<n;i++) cout << a[i] << ' ';
    cout << endl;
    insert_sort();
    for(int i=0;i<n;i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
}