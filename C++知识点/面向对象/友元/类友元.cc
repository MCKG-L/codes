#include <iostream>
#include <string>
using namespace std;
class Building;//可以先声明
class Goodgay{
public:
    Goodgay();
    void visit();//访问Building中的属性
    Building *building;

};
class Building{
    //友元类
friend class Goodgay;
public:
    Building();
    string m_sittingroom;
private:
    string m_beddingroom;
};
Building::Building(){
    m_sittingroom = "客厅";
    m_beddingroom = "卧室";
}
void Goodgay::visit(){
    cout << "好基友正在访问：" << building->m_sittingroom << endl;
    cout << "好基友正在访问：" << building->m_beddingroom << endl;
}
Goodgay::Goodgay(){
    //创建建筑物对象
    building = new Building;
}
void test01(){
    Goodgay g;
    g.visit();
}
int main()
{   
    test01();
}