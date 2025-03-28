#include <iostream>
using namespace std;
//无头节点链表
struct ListNode{
    int data;//数据 可以放一个结构
    ListNode * next;//指针
    ListNode(int x):data(x),next(NULL){}
};
void PrintList(ListNode *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode* Reverse_List(ListNode *head){
    ListNode *pre = NULL;
    ListNode *next = NULL;
    while(head != NULL){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
int main()
{
    ListNode *head = new ListNode(1);//head是链表的首地址
    // ListNode h2(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    PrintList(head);
    //链表反转
    head = Reverse_List(head);
    PrintList(head);

}