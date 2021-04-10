//
// Created by Criss Allan on 2021/4/10.
//

/*
 * 在一个二维数组中，每一行按照从左到右的递增顺序顺序排列，每一列都按照从上到下的递增顺序排列。
 * 请完成一个函数，输入这样的一个二维数组以及一个整数，判断数组中是否含有该整数。
 */
# include <iostream>


bool Find(int* matrix, int rows, int cols, int number)
{
    bool found = false;

    if (matrix != nullptr && rows > 0 && cols > 0)
    {
        int row_idx = 0;
        int col_idx = cols - 1;
        while(row_idx < rows && col_idx >= 0)
        {
            if (matrix[row_idx * cols + col_idx] == number)
            {
                found = true;
                break;
            }
            else if (matrix[row_idx * cols + col_idx] > number)
                --col_idx;
            else
                ++row_idx;
        }
    }
    return found;
}

int main()
{
    int matrix[] = {1, 2, 8, 9,
                    2, 4, 9, 12,
                    4, 7, 10, 13,
                    6, 8, 11, 15};
    int numbers_1 = 5;
    int numbers_2 = 7;
    bool res_1 = Find(matrix, 4, 4, numbers_1);
    bool res_2 = Find(matrix, 4, 4, numbers_2);
    std::cout << "Find 5 in matrix? " << res_1 << std::endl;
    std::cout << "Find 7 in matrix? " << res_2 << std::endl;
    return 0;
}