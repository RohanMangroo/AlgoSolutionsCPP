#include <vector>
#include <string>
#include <string.h>
using namespace std;

vector<string> *split(string str, char delim);
vector<string> *createStack(vector<string> *strings, string &path);
string *join(vector<string> *stack, string &path);

string shortenPath(string path)
{
    vector<string> *strings = split(path, '/');
    vector<string> *stack = createStack(strings, path);
    string *result = join(stack, path);

    return *result;
}

string *join(vector<string> *stack, string &path)
{
    string *result = path[0] == '/' ? new std::string("/") : new std::string();
    for (int i = 0; i < stack->size(); i++)
    {

        if (i == stack->size() - 1)
            *result += stack->at(i);
        else
            *result += (stack->at(i) + "/");
    }
    return result;
}

vector<string> *createStack(vector<string> *strings, string &path)
{
    vector<string> *stack = new vector<string>;

    for (int i = 0; i < strings->size(); i++)
    {
        if (strings->at(i) == ".")
            continue;

        if (strings->at(i) == "..")
        {
            if (stack->size() > 0)
            {
                if (stack->back() == "..")
                    stack->push_back(strings->at(i));
                else if (stack->back() != "..")
                    stack->pop_back();
            }

            else if (stack->size() == 0)
            {
                if (path[0] != '/')
                    stack->push_back(strings->at(i));
            };
        }

        else
            stack->push_back(strings->at(i));
    }

    return stack;
}

vector<string> *split(string str, char delim)
{
    vector<string> *result = new vector<string>;
    string currString{};

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == delim)
        {
            if (currString.length() > 0)
                result->push_back(currString);
            currString = "";
        }
        else
            currString += str[i];
    }
    if (currString.length() > 0)
        result->push_back(currString);
    return result;
}