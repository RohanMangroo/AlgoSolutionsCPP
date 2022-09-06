#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }

    BST &insert(int val)
    {
        BST *currNode = this;

        while (currNode)
        {
            if (val >= currNode->value && currNode->right == nullptr)
            {
                currNode->right = new BST(val);
                break;
            }
            else if (val < currNode->value && currNode->left == nullptr)
            {
                currNode->left = new BST(val);
                break;
            }

            if (val >= currNode->value)
                currNode = currNode->right;
            else if (val < currNode->value)
                currNode = currNode->left;
        }
        return *this;
    }

    bool contains(int val)
    {
        BST *currNode = this;
        while (currNode)
        {
            if (currNode->value == val)
                return true;
            else if (val >= currNode->value)
                currNode = currNode->right;
            else if (val < currNode->value)
                currNode = currNode->left;
        }
        return false;
    }

    BST &remove(int val, BST *parent = nullptr)
    {
        vector<BST *> nodeToRemoveData;
        vector<BST *> rightSubtreeMinData;

        // finding the data(node and parent) for the node to remove
        nodeToRemoveData = this->getNodeToRemoveData(val, parent);
        BST *nodeToRemoveParent = nodeToRemoveData[0];
        BST *nodeToRemove = nodeToRemoveData[1];

        // nodeToRemove has both left and right children,
        if (nodeToRemove->left && nodeToRemove->right)
        {
            // swap values
            nodeToRemove->value = nodeToRemove->right->getMinValue();
            // recall remove on right subtree because the value to be removed is now in that subtree
            // remember to pass the updated parent
            nodeToRemove->right->remove(nodeToRemove->value, nodeToRemove);
        }

        // parent is nullptr, this is the root node
        // based on the validity of left or right child reassign the pointers
        else if (!nodeToRemoveParent)
            this->reassignBindings();

        // nodeToRemove has only one child, so make the parent point to that child
        else if (nodeToRemoveParent->left == nodeToRemove)
            nodeToRemoveParent->left = nodeToRemove->left ? nodeToRemove->left : nodeToRemove->right;
        else if (nodeToRemoveParent->right == nodeToRemove)
            nodeToRemoveParent->right = nodeToRemove->left ? nodeToRemove->left : nodeToRemove->right;

        return *this;
    }

    void reassignBindings()
    {
        if (this->left != nullptr)
        {
            this->value = this->left->value;
            this->right = this->left->right;
            this->left = this->left->left;
        }
        else if (this->right != nullptr)
        {
            this->value = this->right->value;
            this->left = this->right->left;
            this->right = this->right->right;
        }
    }

    int getMinValue()
    {
        BST *currNode = this;
        while (currNode->left)
            currNode = currNode->left;
        return currNode->value;
    }

    vector<BST *> getNodeToRemoveData(int val, BST *parent)
    {
        BST *currNode = this;

        while (currNode)
        {
            if (currNode->value == val)
                break;

            parent = currNode;
            if (val >= currNode->value)
                currNode = currNode->right;
            else if (val < currNode->value)
                currNode = currNode->left;
        }
        return vector<BST *>{parent, currNode};
    }
};