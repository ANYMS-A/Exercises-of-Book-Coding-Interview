//
// Created by Criss Allan on 2021/5/11.
//
/*
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有的字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向
 * 左右上下移动一格。
 */

# include <iostream>


bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
    if (str[pathLength] == '\0')
        return true;

    bool hasPath = false;

    if (row >= 0 && row < rows && col >= 0 &&
        col < cols && matrix[row * cols + col] == str[pathLength] &&
        !visited[row * cols + col])
    {
        ++pathLength;
        visited[row * cols + col] = true;
        hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) ||
                  hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) ||
                  hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) ||
                  hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);

        if (!hasPath)
        {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }
    return hasPath;
}


bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
        return false;

    bool* visited = new bool[rows * cols];
    memset(visited, 0, rows * cols); // 初始化为全0

    int pathLength = 0;
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
            {
                return true;
            }
        }
    }
    delete [] visited;
    return false;
}

int main()
{
    char matrix[13] = "abtgcfcsjdeh"; // 数组初始化要多一个空间 存放 '\0'字符

    int rows = 4, cols = 4;
    char str[5] = "bfce";

    if (hasPath(matrix, rows, cols, str))
        std::cout << "Has path!" << std::endl;
    else
        std::cout << "Doesn't have path!" <<std::endl;
}
