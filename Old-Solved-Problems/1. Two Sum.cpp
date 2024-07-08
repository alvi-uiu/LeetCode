#include <bits/stdc++.h>
using namespace std;
// Brute force : T(n)=0(n^2);
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     vector<int> idx;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (nums[i] + nums[j] == target)
//             {
//                 return {i, j};
//             }
//         }
//     }

//     return {};
// }

/*----------------------------------------------------------------------*/

// Optimal : T(n)=0(n);

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int rem = target - nums[i];
        if (mp.find(rem) != mp.end())
        {
            return {i, mp[rem]};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main()
{
    unordered_map<int, int> mp;
    mp[7] = 7;
    // cout << mp[7];

    return 0;
}