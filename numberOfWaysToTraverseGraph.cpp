sing namespace std;
using Grid = vector<vector<int>>;

Grid createGrid(int width, int height);
int dfs(Grid grid, int &numWays, int currRow, int CurrCol, int height, int width);

int numberOfWaysToTraverseGraph(int width, int height)
{
    int numWays{0};
    Grid grid = createGrid(width, height);
    return dfs(grid, numWays, 0, 0, height, width);
}

int dfs(Grid grid, int &numWays, int currRow, int currCol, int height, int width)
{
    if (currRow < 0 || currRow >= height || currCol < 0 || currCol >= width)
        return numWays;
    if (currRow == height - 1 && currCol == width - 1)
        numWays++;

    dfs(grid, numWays, currRow + 1, currCol, height, width);
    dfs(grid, numWays, currRow, currCol + 1, height, width);

    return numWays;
}

Grid createGrid(int width, int height)
{
    vector<int> row(width, 0);
    Grid grid(height, row);
    return grid;
}