/*

And that each person will only have what they endeavoured towards , [53:39]

and that ˹the outcome of˺ their endeavours will be seen ˹in their record˺ , [53:40]

then they will be fully rewarded . [53:41]

*/

#include <bits/stdc++.h>
using namespace std;

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
    }
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        vector<int> ans(n + m);
        int left = 0;
        int right = 0;

        int index = 0;

        while (left < n && right < m)
        {
            if (nums1[left] <= nums2[right])
            {
                ans[index] = nums1[left];
                left++, index++;
            }
            else
            {
                ans[index] = nums2[right];
                right++, index++;
            }
        }

        // if still elements left :

        while (left < n)
        {
            ans[index++] = nums1[left++];
        }

        while (right < m)
        {
            ans[index++] = arr2[right++];
        }

        // Fill back the elements from ans[]
        // to nums1[] and arr2[]:
        for (int i = 0; i < n + m; i++)
        {
            if (i < n)
                nums1[i] = ans[i];
            else
                nums2[i - n] = ans[i];
        }
    }
};

int32_t main()
{
    fast_io();

    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}