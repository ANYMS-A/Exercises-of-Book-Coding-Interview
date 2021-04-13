//
// Created by Criss Allan on 2021/4/12.
//
/*
 * 请实现一个函数，把字符串中的每个空格替换成"%20"。例如，输入"We are happy.", 输出"We%20are%20happy."
 */
#include <iostream>
#include <stdio.h>

void ReplaceBlank(char string[], int capacity)
{
    if(string == nullptr || capacity <= 0)
        return;

    int originalLength = 0;
    int numOfBlank = 0;

    int idx = 0;
    while(string[idx] != '\0')
    {
        originalLength++;
        if(string[idx] == ' ')
            numOfBlank++;
        idx++;
    }

    int newLength = originalLength + 2 * numOfBlank;

    if(newLength > capacity)
        return;

    int idxOfOriginal = originalLength;
    int idxOfNew = newLength;

    while(idxOfOriginal >= 0 && idxOfNew > idxOfOriginal)
    {
        if (string[idxOfOriginal] == ' ')
        {
            string[idxOfNew--] = '0';
            string[idxOfNew--] = '2';
            string[idxOfNew--] = '%';
        }
        else
        {
            string[idxOfNew--] = string[idxOfOriginal];
        }
        --idxOfOriginal;
    }
    return;
}


int main()
{
    const int capacity = 50;
    char string[capacity] = "We are happy.";
    ReplaceBlank(string, capacity);
    std::cout << string << std::endl;
    return 0;
}