#include <iostream>
#include <vector>

using namespace std;

bool potentialPeak(vector<int> array, int currPos)
{
    int currValue{array.at(currPos)};
    int leftValue{array.at(currPos - 1)};
    int rightValue{array.at(currPos + 1)};

    return leftValue < currValue && rightValue < currValue;
};

int traverse(vector<int> array, int currPos, int direction)
{
    int length{0};

    while (array.at(currPos + direction) < array.at(currPos))
    {
        length++;
        currPos = currPos + direction;
        if (currPos == 0 || currPos == array.size() - 1)
            break;
    }
    return length;
};

int longestPeak(vector<int> array)
{
    if (array.size() == 0)
        return 0;
    int maxLength{0};

    for (int i = 1; i < array.size() - 1; i++)
    {
        if (!(potentialPeak(array, i)))
            continue;

        int leftlength = traverse(array, i, -1);
        int rightLength = traverse(array, i, 1);
        int totalPeakLength = leftlength + rightLength;

        if (totalPeakLength > maxLength)
            maxLength = totalPeakLength;
    }

    if (maxLength == 0)
        return 0;
    return maxLength + 1;
};

int main()
{

    vector<int> array{1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    int result = longestPeak(array);
    cout << result << endl;
    return 0;
};