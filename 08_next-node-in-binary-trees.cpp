//
// Created by Criss Allan on 2021/4/27.
//

/*
 * 给定一颗二叉树和其中的一个节点，如何找出中序遍历序列的下一个节点？树中的节点除了有两个分别指向左右子节点的指针，还有一个指向父节点
 * 的指针。
 */

#include <exception>
#include <stdexcept>
#include <iostream>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* p_leftChild;
    BinaryTreeNode* p_rightChild;
    BinaryTreeNode* p_parent;
};


/*
 * 上一题重建二叉树的代码在此题作为辅助，用来重建二叉树, 不过做了一些改进，重建的过程中需要标明节点的parentNode，不过改动非常简单
 */

BinaryTreeNode* ConstructCore(int*, int*, int*, int*, BinaryTreeNode*);

BinaryTreeNode* Construct(int* p_preOrders, int* p_midOrders, int length)
{
    // 判断输入是否合法
    if (p_preOrders == nullptr || p_midOrders == nullptr || length == 0)
        return nullptr;
    // 调用辅助函数
    return ConstructCore(p_preOrders, p_preOrders + length - 1, p_midOrders, p_midOrders + length - 1, nullptr);

}

BinaryTreeNode* ConstructCore
        (
                int* startPreOrder, int* endPreOrder,
                int* startMidOrder, int* endMidOrder,
                BinaryTreeNode* p_parentNode
        )
{
    std::logic_error ex("Invalid Input.");
    int rootValue = startPreOrder[0];
    BinaryTreeNode* rootNode = new BinaryTreeNode();
    rootNode->value = rootValue;
    rootNode->p_leftChild = rootNode->p_rightChild = nullptr;
    rootNode->p_parent = p_parentNode;

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
                                              startMidOrder, rootMidOrder - 1, rootNode);
    }
    if (leftLength < endPreOrder - startPreOrder)
    {
        //构建右子树
        rootNode->p_rightChild = ConstructCore(leftPreOrderEnd + 1, endPreOrder,
                                               rootMidOrder + 1, endMidOrder, rootNode);
    }
    return rootNode;
}


BinaryTreeNode* getNextNodeInMidOrder(BinaryTreeNode* pNode)
{
    if (pNode == nullptr)
        return nullptr;

    BinaryTreeNode* pNextNode = nullptr;

    // 如果存在右子树
    if (pNode->p_rightChild != nullptr)
    {
        // 顺着右子树的左子节点一直找，找到的叶子节点，就是中序遍历的下一个节点
        BinaryTreeNode* pRight = pNode->p_rightChild;
        while (pRight->p_leftChild != nullptr)
            pRight = pRight->p_leftChild;
        pNextNode = pRight;
    }
    // 如果不存在右子树
    else
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->p_parent;
        // 如果当前节点是其父节点的右子节点，一直顺着父亲节点找回去，直到当前节点是其父亲节点的左子节点，就是中序遍历的下一个节点
        while (pParent != nullptr && pCurrent == pParent->p_rightChild)
        {
            pCurrent = pParent;
            pParent = pCurrent->p_parent;
        }
        // 如果当前节点是其父节点的左子节点，那么其父节点就是中序遍历的下一个节点
        pNextNode = pParent;
    }
    return pNextNode;
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

    BinaryTreeNode* testNode = rootNode->p_rightChild->p_leftChild;

    BinaryTreeNode* nextNodeOfTestNode = getNextNodeInMidOrder(testNode);
    std::cout << "The input node is:" << testNode->value << std::endl;
    std::cout << "Its next node in Mid Order is: " << nextNodeOfTestNode->value << std::endl;
}