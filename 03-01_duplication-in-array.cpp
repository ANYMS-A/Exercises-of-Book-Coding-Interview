//
// Created by Criss Allan on 2021/4/5.
//
/*
 * 在一个长度为n的数组里，所有的数字都在0～n-1的范围内。数组中的某些数字是重复的，但不知道有几个数字重复了，也不知道那些数字重复了几次。
 * 请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组[2,3,1,0,2,5,3]，那么对应的输出的重复的数字是2或者3。
 */
#include <iostream>

bool find_duplicate(int numbers[], int length, int* duplication)
{
    // 判断数组是否为空，数组长度是否大于0
    if (numbers == nullptr || length <= 0)
        return false;

    for (int i = 0; i < length; ++i)
    {
        // 判断元素是否在0～n-1之间
        if (numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }

    for (int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            if (numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            // 交换第numbers[i]和numbers[numbers[i]]的值
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}

//测试用例
int main()
{
    int numbers[] = {2,3,1,0,2,5,3};
    int length = 7;
    int* duplication = numbers;
    bool find = find_duplicate(numbers, length, duplication);
    if (find)
    {
        std::cout << *duplication << std::endl;
    }
    else
        std::cout << "Not find!" << std::endl;
    return 0;
}