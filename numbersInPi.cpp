#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;
using obj = unordered_map<string, bool>;

class Data
{
public:
    string pi;
    int total;
    obj lookUp;

    // Constructor
    Data(string &pi, int total, vector<string> &numbers)
    {
        this->pi = pi;
        this->total = total;
        this->lookUp = this->createLookUp(numbers);
    }

    // Methods
    obj createLookUp(vector<string> &numbers)
    {
        obj strLookUp{};
        for (auto str : numbers)
            strLookUp[str] = true;
        return strLookUp;
    };

    bool keyInMap(string key)
    {
        if (this->lookUp.find(key) == this->lookUp.end())
            return false;
        else
            return true;
    };
};

//==========================================================================//

void getNumbers(Data &data, string currString, int currPos, int currCount);

int numbersInPi(string pi, vector<string> numbers)
{
    Data data = Data(pi, INT_MAX, numbers);
    getNumbers(data, "", 0, 0);

    if (data.total == INT_MAX)
        return -1;
    else
        return data.total;
}

void getNumbers(Data &data, string currString, int currPos, int currCount)
{
    for (int i = currPos; i < data.pi.length(); i++)
    {
        if (data.keyInMap(currString))
            getNumbers(data, "", i, currCount + 1);
        currString += data.pi[i];
    }
    if (data.keyInMap(currString))
        data.total = min(data.total, currCount);
}
