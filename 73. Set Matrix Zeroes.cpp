/*

وَأَن لَّيْسَ لِلْإِنسَـٰنِ إِلَّا مَا سَعَىٰ

and that each person will only have what they endeavoured towards,

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

void mark_row(int i, vector<vector<int>> &matrix, int m)
{

    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
            matrix[i][j] = -99;
    }
}

void mark_col(int j, vector<vector<int>> &matrix, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
            matrix[i][j] = -99;
    }
}

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        ll n = matrix.size();
        ll m = matrix[0].size();
        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    mark_row(i, matrix, m);
                    mark_col(j, matrix, n);
                    flag = true;
                }
            }
        }

        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (matrix[i][j] == -99)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // print if there was any of 0 :

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << matrix[i][j] << ",";
            }
            cout << "\n";
        }

        return;
    }
};

// int32_t main()
// {
//     return 0;
// }