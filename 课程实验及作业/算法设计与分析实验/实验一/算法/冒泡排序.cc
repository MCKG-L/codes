#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int N = 10010;
int a[N],n;
void Bubble_sort(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]) swap(a[j],a[j+1]);
        }
    }
}
int main()
{
    srand(time(NULL));
    n = rand() % 12 + 1;
    for(int i=0;i<n;i++) a[i] = rand() % 100 + 1;
    for(int i=0;i<n;i++) cout << a[i] << ' ';
    cout << endl;
    Bubble_sort();
    for(int i=0;i<n;i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
}