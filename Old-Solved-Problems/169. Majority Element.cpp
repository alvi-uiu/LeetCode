#include <bits/stdc++.h>
using namespace std;

// Brute force : 0(n^2)
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[i] == nums[j])
                cnt++;
            if (cnt > n / 2)
                return nums[i];
        }
    }

    return 0;
}

// Better : T(n)=0(nlogn)+0(n) : S(n)=0(n)

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second > n / 2)
            return it.first;
    }

    return 0;
}

// Optimal :

int majorityElement(vector<int> &nums)
{
    int majElem = nums[0];
    int cnt = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == majElem)
        {
            cnt++;
        }
        else if (nums[i] != majElem)
            cnt--;
        else if (cnt == 0)
        {
            majElem = nums[i];
            cnt = 1;
        }
    }

    return majElem;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3, 4, 5, 7, 8, 7};

    return 0;
}