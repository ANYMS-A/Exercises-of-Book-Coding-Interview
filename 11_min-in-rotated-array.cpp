//
// Created by Criss Allan on 2021/5/9.
//

/*
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序数组的一个旋转，输出旋转数组的最小元素。例如，数组
 * {3, 4, 5, 1, 2}是{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
 * 解题思路：使用类似二分查找的思想，可以将O(n)的查找复杂度降低至O(log(n))
 */
#include <exception>
#include <iostream>

int findMinInOrder(int* numbers, int start_idx, int end_idx)
{
    /*
     * 顺序查找最小数的函数，复杂度是O(n)。适用于当无法通过start_idx， end_idx, mid_idx缩小查找范围的时候。
     */
    int result = numbers[start_idx];
    for(int i = start_idx + 1; i < end_idx; ++i)
    {
        if (result > numbers[i])
            result = numbers[i];
    }
    return result;

}


int findMin(int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
    {
        std::logic_error ex("Invalid input!");
        throw ex;
    }

    int start_idx = 0;
    int end_idx = length - 1;
    int mid_idx = start_idx;  // 先将start索引赋值给mid索引
    while(numbers[start_idx] >= numbers[end_idx])
    {
        if(end_idx - start_idx == 1)
        {
            // 如果只有两个元素，且满足了之前的条件，那么最小的数字就是第二个数
            mid_idx = end_idx;
            break;
        }

        mid_idx = (start_idx + end_idx) / 2;
        if(numbers[start_idx] == numbers[end_idx] && numbers[mid_idx] == numbers[start_idx])
            return findMinInOrder(numbers, start_idx, end_idx);

        if(numbers[mid_idx] >= numbers[start_idx])
            start_idx = mid_idx;
        else if (numbers[mid_idx] <= numbers[end_idx])
            end_idx = mid_idx;

    }
    return numbers[mid_idx];
}

int main()
{
    int numbers[6] = {3, 4, 5, 1, 2, 3};
    int length = 6;
    std::cout << findMin(numbers, length) << std::endl;
}