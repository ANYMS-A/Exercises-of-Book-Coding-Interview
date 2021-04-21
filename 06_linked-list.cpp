//
// Created by Criss Allan on 2021/4/18.
//
#include <iostream>
#include <stack>
/*
 * 输入一个链表的头节点，从尾到头打印一个链表
 * 考虑使用栈做数据结构
*/

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

void printLinkedListReversely(ListNode* pHead)
{
    std::stack<ListNode*> nodes;
    ListNode* tmpNode = pHead;
    // 入栈
    while(tmpNode != nullptr)
    {
        nodes.push(tmpNode);
        tmpNode = tmpNode->next;
    }
    // 出栈
    while(!nodes.empty())
    {
        ListNode *tmpNode = nodes.top();
        std::cout << tmpNode->value << std::endl;
        nodes.pop();
    }
}


int main()
{
    using namespace std;

    auto* head = new ListNode();
    head->value = -1;
    head->next = nullptr;

    for (int i = 0; i < 50; i++)
    {
        AddToTail(&head, i);
    }

    printLinkedListReversely(head);

    return 0;
}

