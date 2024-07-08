/*

And that each person will only have what they endeavoured towards , [53:39]

and that ˹the outcome of˺ their endeavours will be seen ˹in their record˺ , [53:40]

then they will be fully rewarded . [53:41]

*/

#include <bits/stdc++.h>
using namespace std;

void maxSubArray(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();
    int maxSubSum = INT_MIN;
    int sum = 0;

    for (int j = 0; j < n; j++)
    {
        sum += nums[j];

        maxSubSum = max(maxSubSum, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << maxSubSum;
}

int32_t main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        nums.push_back(k);
    }

    // for (auto it : nums)
    // {

    //     cout << it << " ";
    // }

    maxSubArray(nums);

    return 0;
}