#include <iostream>
#include <vector>

using namespace std;

void visitNeighbors(vector<vector<int>> &matrix, int row, int col)
{
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix.at(0).size())
        return;
    if (matrix.at(row).at(col) != 1)
        return;

    matrix.at(row).at(col) = 2;

    visitNeighbors(matrix, row + 1, col);
    visitNeighbors(matrix, row - 1, col);
    visitNeighbors(matrix, row, col + 1);
    visitNeighbors(matrix, row, col - 1);
}

void traverseRow(vector<vector<int>> &matrix, int row)
{
    for (int col = 0; col < matrix.at(0).size(); col++)
    {
        int currValue{matrix.at(row).at(col)};
        if (currValue == 1)
            visitNeighbors(matrix, row, col);
    }
}

void traverseCol(vector<vector<int>> &matrix, int col)
{
    for (int row = 0; row < matrix.size(); row++)
    {
        int currValue{matrix.at(row).at(col)};
        if (currValue == 1)
            visitNeighbors(matrix, row, col);
    }
}

void switchValues(vector<vector<int>> &matrix)
{
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix.at(0).size(); col++)
        {
            int currValue{matrix.at(row).at(col)};
            if (currValue == 1)
                matrix.at(row).at(col) = 0;
            if (currValue == 2)
                matrix.at(row).at(col) = 1;
        }
    }
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix)
{
    traverseRow(matrix, 0);
    traverseRow(matrix, matrix.size() - 1);
    traverseCol(matrix, 0);
    traverseCol(matrix, matrix.at(0).size() - 1);
    switchValues(matrix);

    return matrix;
}

int main()
{
    return 0;
}