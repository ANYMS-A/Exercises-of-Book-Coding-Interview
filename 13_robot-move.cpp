//
// Created by Criss Allan on 2021/5/17.
//
/*
 * 地上有一个m行n列的方格。一个机器人从坐标（0， 0）的格子开始移动，它每次可以向左，右，上，下移动一个格子。但是不能进入行坐标和列坐标的
 * 数位之和大于k的格子。请问该机器人能够到达多少个格子。例如：k为18时，机器人可以进入格子（35， 37）因为3+5+3+7=18。但是它不能进入方格
 * （35， 38）因为3+5+3+8 > 18。
 */
#include <iostream>


int getDigitSum(int number)
{
    /*
     * 输入一个数字，计算该数字各个位数之和
     */
    int sum = 0;
    while(number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
    /*
     * 用此函数来判断机器人能否进入（row, col）为坐标的方格。
     */
    if (row >= 0 && row < rows && col >= 0 && col < cols &&
        getDigitSum(col) + getDigitSum(row) <= threshold &&
        !visited[row * cols + col])
        return true;
    return false;
}


int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
    int count = 0;
    if (check(threshold, rows, cols, row, col, visited))
    {
        visited[row * cols + col] = true;
        count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited) +
                    movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                    movingCountCore(threshold, rows, cols, row, col + 1, visited) +
                    movingCountCore(threshold, rows, cols, row, col - 1, visited);
    }
    return count;
}

int movingCount(int threshold, int rows, int cols)
{
    if (threshold < 0 || rows <= 0 || cols <= 0)
        return 0;
    bool* visited = new bool[rows * cols];
    for (int i = 0; i < rows * cols; ++i)
        visited[i] = false;
    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
    delete [] visited;
    return count;
}

int main()
{
    int threshold = 18;
    int rows = 40, cols = 40;
    int count = movingCount(threshold, rows, cols);
    std::cout << "The robot can achieve: " << count << " grids in a " << rows << " by " << cols << " grid board!" << std::endl;
}
