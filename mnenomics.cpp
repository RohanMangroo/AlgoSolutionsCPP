#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, std::string> createMap();
void helperFunction(unordered_map<char, std::string> &map, vector<std::string> &collection,
                    int currPos, vector<char> &vecString, std::string num);

vector<string> phoneNumberMnemonics(std::string phoneNumber)
{
    unordered_map<char, std::string> map = createMap();
    vector<std::string> collection;
    vector<char> chars;
    helperFunction(map, collection, 0, chars, phoneNumber);

    return collection;
}
void helperFunction(unordered_map<char, std::string> &map, vector<std::string> &collection,
                    int currPos, vector<char> &vecString, std::string num)
{

    if (vecString.size() == num.length())
    {
        std::string s(vecString.begin(), vecString.end());
        collection.push_back(s);
        return;
    }
    char currChar = num.at(currPos);
    std::string stringToLoop = map.at(currChar);

    for (size_t i = 0; i < stringToLoop.length(); i++)
    {
        vecString.push_back(stringToLoop[i]);
        helperFunction(map, collection, currPos + 1, vecString, num);
        vecString.pop_back();
    }
}

unordered_map<char, std::string> createMap()
{
    unordered_map<char, std::string> map{};
    map.insert({'0', "0"});
    map.insert({'1', "1"});
    map.insert({'2', "abc"});
    map.insert({'3', "def"});
    map.insert({'4', "ghi"});
    map.insert({'5', "jkl"});
    map.insert({'6', "mno"});
    map.insert({'7', "pqrs"});
    map.insert({'8', "tuv"});
    map.insert({'9', "wxyz"});

    return map;
}