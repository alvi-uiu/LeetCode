#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        vector<vector<int>> ans;

        if (intervals.size() == 1)
        {
            ans.push_back(intervals[0]);
            return ans;
        }

        ans.push_back(intervals[0]); // to avoid runtime error !

        for (int i = 1; i < n; i++)
        {

            vector<int> &prev_interval = ans.back(); // taking address to assign new interval
            int prev_interval_end = prev_interval[1];

            int cur_interval_start = intervals[i][0];
            int cur_interval_end = intervals[i][1];

            if (cur_interval_start <= prev_interval_end)
            {
                prev_interval[1] = max(prev_interval_end, cur_interval_end);
            }
            else
            {
                ans.emplace_back(intervals[i]);
            }
        }

        return ans;
    }
};

int main()
{ // heres how 2D vector works :

    // int numRows, numCols;
    // cout << "Enter the number of rows: ";
    // cin >> numRows;
    // cout << "Enter the number of columns: ";
    // cin >> numCols;

    // vector<vector<int>> arr(numRows, vector<int>(numCols));

    // cout << "Enter the elements of the matrix:\n";
    // for (int i = 0; i < numRows; ++i)
    // {
    //     for (int j = 0; j < numCols; ++j)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    // vector<int> &v = arr.back();

    // for (auto it : v)
    // {

    //     cout << it << " ";
    // }

    // cout << endl;

    // int y = v[1];

    // cout << y;

    // Printing the elements of the matrix (optional)
    // cout << "The elements of the matrix are:\n";
    // for (int i = 0; i < numRows; ++i)
    // {
    //     for (int j = 0; j < numCols; ++j)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    // // Printing the elements of the matrix (optional)
    // cout << "The elements of the matrix are:\n";
    // for (int i = 0; i < numRows; ++i)
    // {
    //     cout << arr[i][0];
    //     cout << endl;
    // }

    return 0;
}
