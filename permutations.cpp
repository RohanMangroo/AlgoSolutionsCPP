#include <vector>
using namespace std;

vector<int> removeElement(vector<int> array, int currPos);
void permHelper(vector<int> array, vector<int> currPerm, vector<vector<int>> &collection);

vector<vector<int>> getPermutations(vector<int> array)
{
    vector<vector<int>> collection{};
    permHelper(array, {}, collection);
    return collection;
}

void permHelper(vector<int> array, vector<int> currPerm, vector<vector<int>> &collection)
{
    if (array.size() == 0 && currPerm.size() > 0)
        collection.push_back(currPerm);
    for (int i = 0; i < array.size(); i++)
    {
        vector<int> newPerm = currPerm;
        newPerm.push_back(array[i]);
        vector<int> newArray = removeElement(array, i);
        permHelper(newArray, newPerm, collection);
    }
}

vector<int> removeElement(vector<int> array, int currPos)
{
    vector<int> result{};
    for (int i = 0; i < array.size(); i++)
    {
        if (i != currPos)
            result.push_back(array[i]);
    }
    return result;
}