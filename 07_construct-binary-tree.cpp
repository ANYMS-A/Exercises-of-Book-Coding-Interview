//
// Created by Criss Allan on 2021/4/26.
//
/*
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如，输入前序遍历序列
 * {1,2,4,7,3,5,6,8}和中序遍历的结果{4,7,2,1,5,3,8,6}。请重建出该二叉树。
 *
 * 解题思路：前序遍历的第一个节点是根结点，根据前序遍历的根结点的值，找到根结点在中序遍历的位置。在中序遍历中，根结点左边的，都是左子树的
 * 节点，根结点右边的，都是右子树的节点。同样的逻辑适用于左右子树，因此可以考虑递归。
 */
#include <exception>
#include <stdexcept>
#include <iostream>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* p_leftChild;
    BinaryTreeNode* p_rightChild;
};

BinaryTreeNode* ConstructCore(int*, int*, int*, int*);


BinaryTreeNode* Construct(int* p_preOrders, int* p_midOrders, int length)
{
    // 判断输入是否合法
    if (p_preOrders == nullptr || p_midOrders == nullptr || length == 0)
        return nullptr;
    // 调用辅助函数
    return ConstructCore(p_preOrders, p_preOrders + length - 1, p_midOrders, p_midOrders + length - 1);

}

BinaryTreeNode* ConstructCore
(
    int* startPreOrder, int* endPreOrder,
    int* startMidOrder, int* endMidOrder
)
{
    std::logic_error ex("Invalid Input.");
    int rootValue = startPreOrder[0];
    BinaryTreeNode* rootNode = new BinaryTreeNode();
    rootNode->value = rootValue;
    rootNode->p_leftChild = rootNode->p_rightChild = nullptr;

    // 当子树只有一个节点
    if (startPreOrder == endPreOrder)
    {
        if (startMidOrder == endMidOrder && *startPreOrder == *startMidOrder)
            return rootNode;
        else
            throw std::exception(ex);
    }
    // 在中序遍历中找到根结点的值
    int* rootMidOrder = startMidOrder;
    while (rootMidOrder <= endMidOrder && *rootMidOrder != rootValue)
        rootMidOrder++;
    // 检查while弹出后结果是否合法
    if (rootMidOrder == endMidOrder && *rootMidOrder != rootValue)
        throw std::exception(ex);

    int leftLength = rootMidOrder - startMidOrder;
    int* leftPreOrderEnd = startPreOrder + leftLength;
    if (leftLength > 0)
    {
        //构建左子树
        rootNode->p_leftChild = ConstructCore(startPreOrder + 1,leftPreOrderEnd,
                startMidOrder, rootMidOrder - 1);
    }
    if (leftLength < endPreOrder - startPreOrder)
    {
        //构建右子树
        rootNode->p_rightChild = ConstructCore(leftPreOrderEnd + 1, endPreOrder,
                rootMidOrder + 1, endMidOrder);
    }
    return rootNode;
}

void checkBinaryTree(BinaryTreeNode* root)
{
    if (root == nullptr)
        return;
    //前序遍历一下，检查重建后的树是否能对上输入
    std::cout << root->value << std::endl;
    checkBinaryTree(root->p_leftChild);
    checkBinaryTree(root->p_rightChild);
}

int main()
{
    int preOrder[8] = {1,2,4,7,3,5,6,8};
    int midOrder[8] = {4,7,2,1,5,3,8,6};
    int length = 8;

    BinaryTreeNode* rootNode = Construct(preOrder, midOrder, length);
    checkBinaryTree(rootNode);


}