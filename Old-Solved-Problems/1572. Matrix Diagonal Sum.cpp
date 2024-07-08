#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int row = 0;
        // this alfa will modify how each 1D vector will  calculate sum
        auto alfa = [&](int sum, vector<int> vec)
        {
            if (vec[row] == vec[vec.size() - row - 1])
            {
                sum += vec[row];
            }
            else
            {
                sum += vec[row] + vec[vec.size() - row - 1];
            }

            row++;
            return sum;
        };

        int res = accumulate(begin(mat), end(mat), 0, alfa); // will try to accumulate  1D vectors
        return res;
    }
};

// int main()
// {

//     return 0;
// }