/*

وَأَن لَّيْسَ لِلْإِنسَـٰنِ إِلَّا مَا سَعَىٰ

and that each person will only have what they endeavoured towards,

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

/*  BRUTE :

    T : 0(n ^ 3)
    S : 0(1)

*/

//__________________________________________________________

/* void mark_row(int i, vector<vector<int>> &matrix, int m)
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
        bool any0 = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    mark_row(i, matrix, m);
                    mark_col(j, matrix, n);
                    any0 = true;
                }
            }
        }

        if (any0) // if the matrix doesnot contain 0 , no need to modify
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

        // print :

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
*/

/*



*/

/*  BETTER :

    T : 0(n ^ 3)
    S : 0(1)

*/

//__________________________________________________________

/*class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> mark_row(n, 0); //to keep record of marked rows
        vector<int> mark_col(m, 0);

                for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    mark_row[i] = 1;
                    mark_col[j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mark_row[i] == 1 || mark_col[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // print :

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
};*/

/*  OPTIMAL  :

    T : 0(n ^ 2)
    S : NA
*/
//__________________________________________________________
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1; // as matrix[0][0] is a common part so take col0 separately

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // mark_row

                    if (j != 0)
                    {
                        matrix[0][j] = 0; // mark_col
                    }
                    else if (j == 0) // first col
                    {
                        col0 = 0;
                    }
                }
            }
        }

        // without marked_row and marked_col part :

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // marked col part:

        for (int j = 1; j < m; j++)
        {
            if (matrix[0][j] == 0 || matrix[0][0] == 0)
                matrix[0][j] = 0;
        }

        // marked row part :

        for (int i = 0; i < n; i++)
        {
            if (col0 == 0 || matrix[i][0] == 0)
            {
                matrix[i][0] = 0;
            }
        }

        // print :

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << matrix[i][j] << ",";
            }
            cout << "\n";
        }
    }
}

;

// int32_t main()
// {
//     return 0;
// }