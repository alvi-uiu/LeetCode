#include <bits/stdc++.h>
using namespace std;

bool BinSearch(vector<int> matrix, int target)
{
    int n = matrix.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (matrix[mid] == target)
            return true;
        else if (matrix[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();    // row/1D arrays
    int m = matrix[0].size(); // each row/1D array size

    for (int i = 0; i < n; i++)
    {

        if (target >= matrix[i][0] && target <= matrix[i][m - 1])
        {
            return BinSearch(matrix[i], target);
        }
    }

    return false;
}

// Optimal :

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = (n * m) - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
            return true;

        else if (target > matrix[row][col])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 11, 13, 17}};
    cout << searchMatrix(matrix, 13);
    return 0;
}