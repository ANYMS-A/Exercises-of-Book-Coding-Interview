//
// Created by Criss Allan on 2021/4/18.
//
#include <iostream>

struct ListNode
{
    int value;
    ListNode* next;
};

void AddToTail(ListNode** pHead, int value)
{
    //pHead指的是链表的头指针的指针

    auto* newNode = new ListNode();
    newNode->value = value;
    newNode->next = nullptr;

    if (*pHead == nullptr)
    {
        // 如果链表里还没有任何node, 那么相当于newNode成为第一个node
        *pHead = newNode;
    }
    else
    {
        ListNode* pNode = *pHead;

        while (pNode->next != nullptr)
        {
            pNode = pNode->next;
        }
        pNode->next = newNode;
    }
}


int main()
{
    using namespace std;

    ListNode node = ListNode();
    cout << node.value << endl;
    cout << node.next << endl;
    return 0;
}

