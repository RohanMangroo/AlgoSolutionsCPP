#include <algorithm>
#include <cstdlib>

// using namespace std;

// This is an input class. Do not edit.
class BinaryTree
{
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

int dfs(BinaryTree *node, bool &isBalanced);

int dfs(BinaryTree *node, bool &isBalanced)
{
    if (!isBalanced)
        return 0;
    if (node == nullptr)
        return 0;

    int leftHeight = dfs(node->left, isBalanced);
    int rightHeight = dfs(node->right, isBalanced);

    int currHeightDifference = std::abs(leftHeight - rightHeight);
    if (currHeightDifference >= 2)
        isBalanced = false;

    return max(leftHeight, rightHeight) + 1;
}

bool heightBalancedBinaryTree(BinaryTree *tree)
{
    bool isBalanced = true;
    dfs(tree, isBalanced);
    return isBalanced;
}
