#include <iostream>
using namespace std;
string str;
int k;
void dfs(){
    if(str[k] == '#'){
        k++;
        return;
    }
    char r = str[k++];
    // cout << r << ' ';
    //左子节点
    dfs();
    // cout << r << ' ';//中序遍历
    dfs();
    cout << r << ' ';
}
int main()
{
    cin >> str;
    dfs();
    return 0;
}