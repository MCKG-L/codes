#include <iostream>
#include <string>
using namespace std;
class Building;
class Goodgay{
public:
    Goodgay();
    void visit();
    Building *building;
};
class Building{
friend void Goodgay::visit();//写法！
public:
    Building();
    string m_sittingroom;
private:
    string m_beddingroom;
};
Building::Building(){
    m_beddingroom = "卧室";
    m_sittingroom = "客厅";
}
Goodgay::Goodgay(){
    building = new Building;
}
void Goodgay::visit(){
    cout << "visit函数正在访问: " << building->m_sittingroom << endl;
    cout << "visit函数正在访问: " << building->m_beddingroom << endl;
    
}
void test(){
    Goodgay g;
    g.visit();
}
int main()
{
    test();
    return 0;
}