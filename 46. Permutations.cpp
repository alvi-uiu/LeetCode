/*

And that each person will only have what they endeavoured towards , [53:39]

and that ˹the outcome of˺ their endeavours will be seen ˹in their record˺ , [53:40]

then they will be fully rewarded . [53:41]

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{

private:
    // method 1 :

    // void rec_permute(vector<int> &nums, vector<int> box, vector<int>taken, vector<vector<int>>&ans)
    // {
    //     // base : if the box size == num array size , store the ans and return from where its being called

    //     if (box.size() == nums.size())
    //     {
    //         ans.emplace_back(box);
    //         return;
    //     }

    //     // for every value of nums if that is not taken, store it in the box (do it till n-1)
    //     // when the box == num array size and being returned, pop it from the box and un-take it
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (!taken[i])
    //         {
    //             box.emplace_back(nums[i]);
    //             taken[i] = 1;
    //             rec_permute(nums, box, taken, ans);
    //             box.pop_back();
    //             taken[i] = 0;
    //         }
    //     }

    // }

    /*  method 1 :

        T : 0(n!*n)
        S : 0(n)

    */

    //__________________________________________________________

    // method 2 :

    void rec_permute(vector<int> nums, vector<vector<int>> &ans, int idx)
    {

        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            rec_permute(nums, ans, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }

    /*  method 2 :

    T : 0(n!*n)
    S : 0(1)

*/

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> box;
        vector<int> taken(nums.size(), 0);
        vector<vector<int>> ans;
        // rec_permute(nums, box, taken, ans); //ans passed by ref
        rec_permute(nums, ans, 0);
        return ans;
    }
};