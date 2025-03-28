#include <iostream>
using namespace std;
class Building{
    //友元函数 函数声明前面加上关键字friend
friend void goodGay(Building &building);
public:
    Building(){
        m_sittingroom = "客厅";
        m_bedroom = "卧室";
    }
public:
    string m_sittingroom;
private:
    string m_bedroom;
};
void goodGay(Building &building){
    cout << "好基友的全局函数正在访问：" << building.m_sittingroom << endl;
    cout << "好基友的全局函数正在访问：" << building.m_bedroom << endl;
}
void test01(){
    Building building;
    goodGay(building);
}
int main()
{   
    test01();
}