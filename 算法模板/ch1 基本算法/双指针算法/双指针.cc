#include <iostream>
using namespace std;
bool check(int i,int j);
int main()
{
    //基本模板
    int i,j,n;
    for(i=0,j=0;i<n;i++){
        while(j < i && check(i,j)) j++;

        //题目的逻辑
    }

    //核心思想
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //逻辑 O(N^2)
        }
    }
    
}