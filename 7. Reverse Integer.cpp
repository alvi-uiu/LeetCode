#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        int max_limit = INT_MAX / 10;
        int min_limit = INT_MIN / 10;
        while (x != 0)
        {
            int lastDgt = x % 10;

            if (rev > max_limit || (rev == max_limit && lastDgt > 7))
                return 0;
            if (rev < min_limit || (rev == min_limit && lastDgt < -8))
                return 0;

            rev = rev * 10 + lastDgt; // rev
            x /= 10;
        }

        return rev;
    }
};

int main()
{
    int x = 9876;
    Solution s;
    cout << s.reverse(x);
    return 0;
}
