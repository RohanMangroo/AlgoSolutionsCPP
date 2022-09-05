#include <vector>
#include <algorithm>

using nestedVec = std::vector<std::vector<int>>;
using namespace std;

void mergeIntervals(vector<int> &currInterval, vector<int> *topInterval);

nestedVec mergeOverlappingIntervals(nestedVec intervals)
{
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b)
              { return a[0] < b[0]; });

    vector<vector<int>> result{intervals[0]};

    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> currInterval = intervals[i];
        int currIntervalStart = currInterval[0];
        int currIntervalEnd = currInterval[1];

        vector<int> *topInterval = &result[result.size() - 1];

        int topIntervalStart = topInterval->at(0);
        int topIntervalEnd = topInterval->at(1);

        if (currIntervalStart <= topIntervalEnd)
            mergeIntervals(currInterval, topInterval);

        else
            result.push_back(currInterval);
    }
    return result;
}

void mergeIntervals(vector<int> &currInterval, vector<int> *topInterval)
{
    topInterval->at(0) = std::min(currInterval[0], topInterval->at(0));
    topInterval->at(1) = std::max(currInterval[1], topInterval->at(1));
}
