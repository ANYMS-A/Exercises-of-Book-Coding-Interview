//
// Created by Criss Allan on 2021/4/12.
//
#include <stdio.h>

int main()
{
    char str1[] = "hello world";
    char str2[] = "hello world";

    /*
     * 为了节省内存，C/C++常常把常量字符串放到单独的一个内存区域。当几个指针赋值给相同的常量字符串时，
     * 他们实际上会指向相同的内存地址。但是用常量内存初始化字符数组时，情况却有所不同。
     */
    char* str3 = "hello world";
    char* str4 = "hello world";

    if (str1 == str2)
        printf("str1 and str2 are same!\n");
    else
        printf("str1 and str2 are not same!\n");

    if (str3 == str4)
        printf("str3 and str4 are same!\n");
    else
        printf("str3 and str4 are not same!\n");
}
