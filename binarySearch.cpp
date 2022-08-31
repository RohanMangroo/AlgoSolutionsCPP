#include <vector>
using namespace std;

int searchHelper(vector<int>, int target, int start, int end);

int binarySearch(vector<int> array, int target)
{
    return searchHelper(array, target, 0, array.size() - 1);
}

int searchHelper(vector<int> array, int target, int start, int end)
{

    while (start <= end)
    {
        int midPointIndex{(start + end) / 2};
        if (array[midPointIndex] == target)
            return midPointIndex;

        if (target <= array[midPointIndex])
            end = midPointIndex - 1;
        if (target > array[midPointIndex])
            start = midPointIndex + 1;
    }

    return -1;
}