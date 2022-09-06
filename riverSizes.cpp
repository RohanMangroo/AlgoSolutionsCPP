#include <vector>
using namespace std;
int dfs(vector<vector<int>> &matrix, int row, int col);

vector<int> riverSizes(vector<vector<int>> matrix)
{
    vector<int> riverSizes{};

    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[0].size(); col++)
        {
            int currCellValue = matrix.at(row).at(col);
            if (currCellValue == 1)
                riverSizes.push_back(dfs(matrix, row, col));
        }
    }
    return riverSizes;
}

int dfs(vector<vector<int>> &matrix, int row, int col)
{
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size())
        return 0;
    if (matrix[row][col] == 0 || matrix[row][col] == 2)
        return 0;

    matrix[row][col] = 2;

    int top = dfs(matrix, row - 1, col);
    int bottom = dfs(matrix, row + 1, col);
    int left = dfs(matrix, row, col - 1);
    int right = dfs(matrix, row, col + 1);

    return top + bottom + left + right + 1;
}
