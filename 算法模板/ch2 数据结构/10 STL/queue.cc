#include <iostream>
#include <queue>
#include <deque>
using namespace std;
int main()
{
    queue<int> q;
    // q.size(); 大小
    // q.empty(); 是否为空
    // q.push(); 添加元素
    // q.front();返回队头元素
    // q.back();返回队尾元素
    // q.pop();弹出队头元素

    //不支持clear() 替代方式
    q = queue<int>();
    priority_queue<int> heap;
    //默认大根堆
    // qq.push();添加一个元素
    // qq.top();返回堆顶元素
    // qq.pop();弹出堆顶元素

    //小根堆的实现
    priority_queue<int,vector<int>,greater<int>> h;

    deque<int> d;//双端队列
    /*
    size()
    empty()
    clear()
    front()
    back()
    push_back()
    push_front()
    [] 小标访问 随机寻址
    begin(),end()迭代器
    缺点：速度非常慢
    */
}