//
// Created by Criss Allan on 2021/4/18.
//
#include <iostream>
using namespace std;

class example
{
public:
    example()
    {
        cout << "调用构造函数" << endl;
    }
    ~example()
    {
        cout << "调用析构函数" << endl;
    }
};

int main()
{
//    long* l;
//    *l = 23223;  // 内建类，没有初始化指针，会报错

    //example e0 = example();

    cout << "e1:" << endl;
    example* e1;
    // 指针声明后一定要做初始化，否则会带来非常隐秘的bug，而不会直接给出显式的错误
    cout << "address e1:" << e1 << endl;


    cout << "e2:" << endl;
    auto* e2 = new example;
    cout << "address e2:" << e2 << endl;

    cout << "e3:" << endl;
    example* e3 = new example();
    cout << "address e3:" << e3 << endl;

    //事实证明 new会调用构造函数，而malloc不会，单纯的声明也不会。

}
