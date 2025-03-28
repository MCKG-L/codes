#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.1415926
using namespace std;
class P{
private:
    double r,h;
public:
    void setR(double R){
        r = R;
    }
    void setH(double H){
        h = H;
    }
    double volume(){
        return PI * r * r * h;
    }
};
int main()
{
    int n;cin >> n;
    P a[n];
    for(int i=0;i<n;i++){
        double r,h;
        cin >> r >> h;
        a[i].setR(r);
        a[i].setH(h);
    }
    double sum=0,ave;
    for(int i=0;i<n;i++){
        sum += a[i].volume();
    }
    ave = sum / n;
    cout << fixed << setprecision(2) << ave << endl;
    return 0;
}