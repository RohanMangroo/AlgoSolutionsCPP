#include <vector>
#include <unordered_map>
using namespace std;

int countDigits(long long n);
int findMaxNum(const vector<int> &array);

vector<int> countingSort(const vector<int> &array, int digitPlace);
unordered_map<int, vector<int>> createBucket();

vector<int> radixSort(vector<int> array)
{
    if (array.size() == 0)
        return array;

    int maxNum = findMaxNum(array);
    int numLength = countDigits(maxNum);
    int digitPlace{1};

    for (int i = 0; i < numLength; i++)
    {
        array = countingSort(array, digitPlace);
        digitPlace *= 10;
    }

    return array;
}

vector<int> countingSort(const vector<int> &array, int digitPlace)
{
    vector<int> sorted{};

    unordered_map<int, vector<int>> bucket = createBucket();

    for (auto num : array)
    {
        int position = (num / digitPlace) % 10;
        bucket[position].push_back(num);
    };

    for (int i = 0; i < 10; i++)
    {
        vector<int> currVec = bucket[i];
        for (auto num : currVec)
        {
            sorted.push_back(num);
        }
    };

    return sorted;
}

unordered_map<int, vector<int>> createBucket()
{
    unordered_map<int, vector<int>> bucket{};
    for (int i = 0; i < 10; i++)
    {
        vector<int> vec{};
        bucket[i] = vec;
    }
    return bucket;
}

int findMaxNum(const vector<int> &array)
{
    int currMax{array[0]};
    for (auto num : array)
    {
        if (num > currMax)
            currMax = num;
    }
    return currMax;
}

int countDigits(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}