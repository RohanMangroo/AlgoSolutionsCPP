#include <vector>
using namespace std;

void mySwap(vector<int> &array, int a, int b);
int modifiedQuicksort(vector<int> &array, int start, int stop);

int quickselect(vector<int> array, int k)
{
    int currPos{-1};
    int start{0};
    int stop = array.size() - 1;

    while (currPos != k - 1)
    {
        currPos = modifiedQuicksort(array, start, stop);

        if (currPos > k - 1)
            stop = currPos - 1;
        else if (currPos < k - 1)
            start = currPos + 1;
    }

    return array[currPos];
}

int modifiedQuicksort(vector<int> &array, int start, int stop)
{
    int pivot = start;
    int left = start + 1;
    int right = stop;

    while (left <= right)
    {
        if (array[left] >= array[pivot] && array[right] < array[pivot])
            mySwap(array, left, right);

        if (array[left] < array[pivot])
            left++;
        if (array[right] >= array[pivot])
            right--;
    }

    mySwap(array, pivot, right);

    return right;
}

void mySwap(vector<int> &array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
