/*

And that each person will only have what they endeavoured towards , [53:39]

and that ˹the outcome of˺ their endeavours will be seen ˹in their record˺ , [53:40]

then they will be fully rewarded . [53:41]

*/

#include <bits/stdc++.h>
using namespace std;

// BRUTE :

/*void rec_permute(int idx, vector<int> nums, vector<vector<int>> &ans)
{

    if (idx == nums.size())
    {
        ans.emplace_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        rec_permute(idx + 1, nums, ans);
        swap(nums[i], nums[idx]);
    }
}

void nextPermutation(vector<int> &nums)
{

    vector<vector<int>> ans;
    rec_permute(0, nums, ans);

    sort(ans.begin(), ans.end());

    for (auto it : ans)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }

    cout << endl;

    if (nums == ans[ans.size() - 1])
    {
        reverse(nums.begin(), nums.end());
        return;
        // return nums;
    }

    else
    {
        for (int it = 0; it < ans.size(); it++)
        {
            if (ans[it] == nums)
            {
                if (it < ans.size() && ans[it + 1] != nums)
                {
                    nums = ans[it + 1];
                    return;
                }
                else
                {
                    nums = ans[it + 2];
                    return;
                }
            }
        }
    }
}
*/

/*  BRUTE :

    T : 0(n!*n)
    S : 0(1)

*/

//_______________________________________________________________________________________

// BETTER :

// void nextPermutation(vector<int> &nums)
// {

//     // Find the next permutation
//     bool next_perm_exists = next_permutation(nums.begin(), nums.end());

//     if (next_perm_exists)
//     {
//         // // Output the next permutation
//         // cout << "Next permutation: ";
//         // for (int num : nums)
//         // {
//         //     cout << num << " ";
//         // }
//         // cout << endl;

//         nums = nums;
//     }
//     else
//     {
//         reverse(nums.rend(), nums.rbegin());
//     }
// }

// OPTIMAL :

void nextPermutation(vector<int> &nums)
{
    int mark_idx = -1; // initilally took -1 as -1 cant be an index
    bool flag = false;
    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i - 1] < nums[i]) // find the elem from right which is lesser than cur elem
        {
            mark_idx = i - 1; // store that idx
            break;
        }
    }

    if (mark_idx == -1) // if there is no elem like that
    {
        reverse(nums.begin(), nums.end()); // just rev the num array
        return;
    }
    else
    {
        int immBig_idx;

        for (int j = nums.size() - 1; j >= mark_idx + 1; j--)
        {
            if (nums[j] > nums[mark_idx]) // find the immidiate bigger elem of the marked elem
            {
                immBig_idx = j; // store that elements idx
                break;
            }
        }

        swap(nums[mark_idx], nums[immBig_idx]);           // swap those two
        reverse(nums.begin() + mark_idx + 1, nums.end()); // rev from after mark idx to last
        return;
    }
}
