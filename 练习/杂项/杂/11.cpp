#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef enum PROC_STATE{
    R=0,E=1
}PROC_STATE;
typedef struct _proc{
    string name;
    int run_time;
    int alloc_time;
    int req_time;
    int pri;
    PROC_STATE state;
    struct _proc *next;
}PROC;
void func(PROC *P,string name,int time,int pri,PROC_STATE state){
    // P->name = name;
    // strcpy(P->name,name);
    P->name = name;
    P->run_time = time;
    P->pri = pri;
    P->state = state;
    P->alloc_time = 0;
    P->req_time = time;
}
//创建五个进程
PROC *P1,*P2,*P3,*P4,*P5,*q;

//优先队列
priority_queue<PROC*> heap;
void init(){
    // q = (PROC*)malloc(sizeof(PROC));
    P1 = (PROC*)malloc(sizeof(PROC));
    P2 = (PROC*)malloc(sizeof(PROC));
    P3 = (PROC*)malloc(sizeof(PROC));
    P4 = (PROC*)malloc(sizeof(PROC));
    P5 = (PROC*)malloc(sizeof(PROC));
    func(P1,"P1",2,1,R);
    func(P2,"P2",3,5,R);
    func(P3,"P3",1,3,R);
    func(P4,"P4",2,4,R);
    func(P5,"P5",4,2,R);
    heap.push(P1);
    heap.push(P2);
    heap.push(P3);
    heap.push(P4);
    heap.push(P5);
    
    // q = P2;
    // P2->next = P4;
    // P4->next = P3;
    // P3->next = P5;
    // P5->next = P1;
    // P1->next = NULL;
}
void print(){
    priority_queue<PROC*> q = heap;
    while(q.size()){
        PROC *P = q.top();
        q.pop();
        cout << "name:" << P->name << " alloc_time:" << P->alloc_time << " req_time: " << P->req_time << " next: " << P->next->name << endl;
    }
}
int main()
{
    init();
    int cnt = 0;
    while(heap.size()){
        auto p = heap.top();
        cout << "第" << ++cnt << "次取出：" << p->name << endl;
        print();
        heap.pop();
        p->alloc_time ++;
        p->req_time --;
        p->pri --;
        if(p->req_time > 0) heap.push(p);
        
    }
    return 0;
}