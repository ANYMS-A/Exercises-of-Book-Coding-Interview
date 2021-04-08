//
// Created by Criss Allan on 2021/4/8.
//
/*
 * 在一个长度为n+1的数组里，所有数字都在1～n的范围内，所以数组中至少有一个数字是重复的。请找出数组中任意一个重复的数字
 * 但不能修改输入的数组。例如，如果输入长度为8的数组{2,3,5,4,3,2,6,7}，那么对应的输出应该是2或者3
 * 时间复杂度：countRange执行O(log(n))次，每次执行时间复杂度是O(n)，因此时间复杂度是：O(nlog(n))
 * 空间复杂度：O（1）
 */

#include <iostream>


int countRange(const int* numbers, int length, int start, int end)
{
    if (numbers == nullptr)
        return 0;

    int count = 0;
    for (int i = 0; i < length; ++i)
        if (numbers[i] >= start && numbers[i] <= end)
            ++count;
    return count;
}


int getDuplication(const int* numbers, int length)
{
    if (numbers == nullptr || length == 0)
        return -1;

    int start = 1;
    int end = length - 1;
    while (end >= start)
    {
        int middle = ((end - start) >> 1 ) + start;
        int count = countRange(numbers, length, start, middle);
        if (end == start)
        {
            if (count > 1)
                return start;
            else
                break;
        }
        if (count > (middle - start + 1))
            end = middle;
        else
            start = middle + 1;
    }
    return -1;
}


int main()
{
    int numbers[] = {2, 3, 5, 4, 3, 2, 6, 7};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int dup = getDuplication(numbers, length);

    if (dup != -1)
        std::cout << "find the duplicated number: " << dup << std::endl;
    else
        std::cout << " Noe find the duplicated number:" << std::endl;
    return 0;
}
