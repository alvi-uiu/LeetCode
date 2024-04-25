/*

And that each person will only have what they endeavoured towards , [53:39]

and that ˹the outcome of˺ their endeavours will be seen ˹in their record˺ , [53:40]

then they will be fully rewarded . [53:41]

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

/*
ll nCr(ll n, ll r)
{

    ll result = 1;

    for (int i = 0; i < r; i++)
    {
        result = result * (n - i) / (i + 1);
    }

    return result;
}
*/

/*  nCr :

    T : 0(r)
    S : NA

*/

//__________________________________________________________

/*vector<vector<int>> generate(int numRows)
{
    int row = numRows;
    vector<vector<int>> ans;
    for (int i = 1; i <= row; i++)
    {
        vector<int> temp;
        for (int j = 1; j <= i; j++)
        {
            temp.push_back(nCr(i - 1, j - 1));
        }
        ans.push_back(temp);
    }

    return ans;
}

/*  generate :

    T : 0(n ^ 3)
    S : 0(1)

*/

//__________________________________________________________

vector<int> generate_row(int n)
{
    vector<int> row;
    ll elem = 1;
    row.emplace_back(1); // because  elem = elem * (n - col) / (col=0) will be inf

    for (int col = 1; col < n; col++)
    {
        elem = elem * (n - col) / (col); // Note : take this parenthesis carefully.
        row.push_back(elem);
    }

    return row;
}
/*


parenthesis taking rule :

ans = ans * (exp)/(exp) ;


*/

/*  generateRow :

    T : 0(n^2)
    S : 0(1)

*/

//__________________________________________________________

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
        {
            ans.emplace_back(generate_row(i));
        }
        return ans;
    }
};