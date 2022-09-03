using namespace std;

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

void findNodeDepths(BinaryTree *node, int &runningSum, int currDepth);

void findNodeDepths(BinaryTree *node, int &runningSum, int currDepth)
{
    if (node == nullptr)
        return;
    runningSum += currDepth;

    findNodeDepths(node->left, runningSum, currDepth + 1);
    findNodeDepths(node->right, runningSum, currDepth + 1);
}

int nodeDepths(BinaryTree *root)
{
    int runningSum = 0;
    findNodeDepths(root, runningSum, 0);

    return runningSum;
}
