//
// Created by Criss Allan on 2021/5/1.
//

/*
 * 用两个栈实现一个队列。队列的声明如下，请实现他的两个函数：appendTail和deleteHead。分别完成在队列尾部插入和在队列头部删除的操作。
 * 解：核心思想便是:
 * 入队时，元素直接压入stack1
 * 出队时，stack2不为空的时候，直接弹出stack2栈顶的元素即可。否则，stack2为空时，需要将stack1的所有元素弹出并压入stack2当中，然后再弹出
 * stack2上面的元素。
 */


#include <iostream>
#include <stack>
#include <exception>

template<typename T>
class CQueue
{
    /*
     * 队列类的声明
     */
public:
    CQueue(){std::cout << "Init CQueue" << std::endl;}
    ~CQueue(){std::cout << "Delete CQueue" << std::endl;}

    void appendTail(const T& Node);
    T deleteHead();

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

// 公有方法实现
template<typename T>
void CQueue<T>::appendTail(const T& Node)
{
    stack1.push(Node);
}

// 公有方法实现
template <typename T>
T CQueue<T>::deleteHead()
{
    std::logic_error ex("The queue is empty.");

    if (stack2.empty())
    {
        while (!stack1.empty())
        {
            T elem = stack1.top();
            stack1.pop();
            stack2.push(elem);
        }
    }
    if(stack2.empty())
        throw std::exception(ex);

    T headNode = stack2.top();
    stack2.pop();
    return headNode;
}

int main()
{
    CQueue<int> myQueue;

    int arr[6] = {1, 2, 3, 4, 5, 6};
    for (int idx = 0; idx < 6; idx++)
    {
        int num = arr[idx];
        myQueue.appendTail(num);
    }

    for (int idx = 0; idx < 6; idx++)
    {
        int head = myQueue.deleteHead();
        std::cout << head << std::endl;
    }
    return 0;
}

