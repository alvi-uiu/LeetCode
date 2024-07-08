#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    for (int k = 2;; k++)
    {
        int sum = (1 << k) - 1;
        if (n % sum == 0)
        {
            cout << n / sum << endl;
            return;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    vector<int> test_cases(t);
    for (int i = 0; i < t; i++)
    {
        cin >> test_cases[i];
    }

    for (int i = 0; i < t; i++)
    {
        solve(test_cases[i]);
    }

    return 0;
}
