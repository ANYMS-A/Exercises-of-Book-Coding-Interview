//
// Created by Criss Allan on 2021/5/4.
//
/*
 * 实现斐波那契数列（非递归的形式）
 */
#include <iostream>

long long fibonacci(unsigned n)
{
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];

    long long nMinusOne = 1;
    long long nMinusTwo = 0;
    long long nVal = 0;
    for (unsigned int i = 2; i < n; i++)
    {
        nVal = nMinusOne + nMinusTwo;
        nMinusTwo = nMinusOne;
        nMinusOne = nVal;
    }
    return n;
}

int main()
{
    unsigned n = 3;
    std::cout << fibonacci(n) << std::endl;
}
