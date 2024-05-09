#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{

    int majElem1 = NULL;
    int cnt1 = 0;
    int majElem2 = NULL;
    int cnt2 = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == majElem1)
        {
            cnt1++;
        }
        else if (nums[i] == majElem2)
        {
            cnt2++;
        }
        else if (cnt1 == 0)
        {
            majElem1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            majElem2 = nums[i];
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // verification :

    vector<int> res;

    int majCnt1 = 0;
    int majCnt2 = 0;

    for (int it : nums)
    {
        if (majElem1 == it)
            majCnt1++;
        else if (majElem2 == it)
            majCnt2++;
    }

    if (majCnt1 > floor(n / 3))
    {
        res.push_back(majElem1);
    }
    if (majCnt2 > floor(n / 3))
    {
        res.push_back(majElem2);
    }

    return res;
}

int main()
{

    return 0;
}