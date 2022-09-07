#include <vector>
#include <algorithm>
#include <typeinfo>
using namespace std;

int waterArea(vector<int> heights)
{
    if (heights.size() == 0)
        return 0;

    int runningSum{0};
    vector<vector<int>> pillarData(heights.size(), vector<int>{});

    int leftMax = 0;
    int rightMax = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        leftMax = max(leftMax, heights[i]);
        pillarData[i].push_back(leftMax);
    }

    for (int j = heights.size() - 1; j >= 0; j--)
    {
        rightMax = max(rightMax, heights[j]);
        pillarData[j].push_back(rightMax);
    }

    for (int i = 0; i < pillarData.size(); i++)
    {
        int pillarMin = min(pillarData[i][0], pillarData[i][1]);
        int waterAmount = pillarMin - heights[i];
        runningSum += waterAmount;
    }

    return runningSum;
}