//
// Created by Criss Allan on 2021/5/6.
//

#include <iostream>
#include <cstdlib>
#include <exception>

int RandomInRange(int start, int end)
{

    if (end < start)
    {
        std::logic_error ex("end should be greater than start");
        throw std::exception(ex);
    }

    int result = (rand() % (end - start + 1)) + start;
    return result;
}

void Swap(int* src, int* tgt)
{
    int tmp = *src;
    *src = *tgt;
    *tgt = tmp;
}

int Partition(int data[], int length, int start, int end)
{
    /*
     * 选择一个数字，将数组中小于这个数字的数移到左边，大于这个数字的数移到右边
     */

    if (data == nullptr || length <= 0 || start < 0 || end >= length)
    {
        std::logic_error ex("Invalid parameter");
        throw std::exception(ex);
    }

    int index = RandomInRange(start, end);
    Swap(&data[index], &data[start]); // 把index所指向的元素放到开头
    int pivot = data[start]; // 中枢元素

    int leftIndex = start;
    int rightIndex = end;
    while (leftIndex < rightIndex)
    {
        while(data[rightIndex] >= pivot && leftIndex < rightIndex)
            rightIndex--;
        if (leftIndex < rightIndex)
            Swap(&data[rightIndex], &data[leftIndex]); // 执行后rightIndex指向的是pivot元素在的位置

        while (data[leftIndex] <= pivot && leftIndex < rightIndex)
            leftIndex++;
        if (leftIndex < rightIndex)
            Swap(&data[rightIndex], &data[leftIndex]); // 执行后leftIndex指向的是pivot元素所在饿位置
    }
    return leftIndex; // 当leftIndex==rightIndex时，partition也完成了
}

void QuickSort(int data[], int start, int end, int length)
{
    if (start >= end)
        return;
    int midIndex = Partition(data, length, start, end);
    QuickSort(data, start, midIndex - 1, length);
    QuickSort(data, midIndex + 1, end, length);
}

int main()
{
    int data[] = {3, 5, 6, 3, 1, 2, 3, 5, 6, 8, 8, 9, 2, 1};
    int start = 0, end = 13, length = 14;
    QuickSort(data, start, end, length);
    for (start=0; start < length; start++)
    {
        std::cout << data[start] << std::endl;
    }
}