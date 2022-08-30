// using namespace std;
// using Grid = vector<vector<int>>;

// Grid createGrid(int width, int height);
// int dfs(Grid grid, int &numWays, int currRow, int CurrCol, int height, int width);

// int numberOfWaysToTraverseGraph(int width, int height)
// {
//     int numWays{0};
//     Grid grid = createGrid(width, height);
//     return dfs(grid, numWays, 0, 0, height, width);
// }

// int dfs(Grid grid, int &numWays, int currRow, int currCol, int height, int width)
// {
//     if (currRow < 0 || currRow >= height || currCol < 0 || currCol >= width)
//         return numWays;
//     if (currRow == height - 1 && currCol == width - 1)
//         numWays++;

//     dfs(grid, numWays, currRow + 1, currCol, height, width);
//     dfs(grid, numWays, currRow, currCol + 1, height, width);

//     return numWays;
// }

// Grid createGrid(int width, int height)
// {
//     vector<int> row(width, 0);
//     Grid grid(height, row);
//     return grid;
// }

// Optimal Solution
#include <iostream>
#include <vector>

using namespace std;
using Grid = vector<vector<int>>;

// Function Prototypes
Grid createGrid(int width, int height);
int calculateWays(Grid &grid, int width, int height);
int findCellValue(Grid &grid, int row, int col, int width, int height);

int numberOfWaysToTraverseGraph(int width, int height)
{
    Grid grid = createGrid(width, height);
    return calculateWays(grid, width, height);
}

int calculateWays(Grid &grid, int width, int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int currValue = grid.at(row).at(col);
            int leftValue = findCellValue(grid, row, col - 1, width, height);
            int topValue = findCellValue(grid, row - 1, col, width, height);

            grid.at(row).at(col) = currValue + leftValue + topValue;
        }
    }
    return grid.at(height - 1).at(width - 1);
}

int findCellValue(Grid &grid, int row, int col, int width, int height)
{
    if (row < 0 || row >= height || col < 0 || col >= width)
        return 0;
    else
        return grid.at(row).at(col);
}

Grid createGrid(int width, int height)
{
    vector<int> row(width, 0);
    Grid grid(height, row);
    grid.at(0).at(0) = 1;
    return grid;
}
