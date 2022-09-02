#include <vector>

using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

void dfs(BinaryTree *node, vector<int> &branchSums, int currSum);

vector<int> branchSums(BinaryTree *root)
{
    vector<int> branchSums{};
    dfs(root, branchSums, 0);
    return branchSums;
}

void dfs(BinaryTree *node, vector<int> &branchSums, int currSum)
{
    if (node == nullptr)
        return;

    int newSum = currSum + node->value;

    dfs(node->left, branchSums, newSum);
    dfs(node->right, branchSums, newSum);

    if (node->left == nullptr && node->right == nullptr)
        branchSums.push_back(newSum);
}