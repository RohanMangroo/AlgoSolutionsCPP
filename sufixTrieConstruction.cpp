#include <unordered_map>
#include <string>
using namespace std;

// Do not edit the class below except for the
// populateSuffixTrieFrom and contains methods.
// Feel free to add new properties and methods
// to the class.
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
};

class SuffixTrie
{
public:
    TrieNode *root;
    char endSymbol;

    SuffixTrie(string str)
    {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }

    void populateSuffixTrieFrom(string str)
    {
        TrieNode *currNode = this->root;

        for (int i = 0; i < str.length(); i++)
        {
            for (int j = i; j < str.length(); j++)
            {
                char currChar = str[j];
                if (this->charInNodeChildren(currNode, currChar))
                    currNode = currNode->children[currChar];
                else
                    this->addCharToNode(currNode, currChar);
            }
            currNode->children[this->endSymbol] = nullptr;
            currNode = this->root;
        }
    }

    bool contains(string str)
    {
        TrieNode *currNode = this->root;
        for (int i = 0; i < str.length(); i++)
        {
            char currChar = str[i];
            if (this->charInNodeChildren(currNode, currChar))
                currNode = currNode->children[currChar];
            else
                return false;
        }
        if (this->charInNodeChildren(currNode, '*'))
            return true;
        else
            return false;
    }

    void addCharToNode(TrieNode *&currNode, char currChar)
    {
        TrieNode *newNode = new TrieNode();
        currNode->children[currChar] = newNode;
        currNode = newNode;
    }

    bool charInNodeChildren(TrieNode *currNode, char currChar)
    {
        if (currNode->children.find(currChar) == currNode->children.end())
            return false;
        return true;
    }
};