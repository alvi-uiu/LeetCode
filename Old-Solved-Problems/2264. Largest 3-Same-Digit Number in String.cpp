#include <bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num)
{
    char mx = ' ';
    for (int i = 2; i < num.length(); i++)
    {

        if (num[i] == num[i - 1] && num[i] == num[i - 2])
        {
            mx = max(mx, num[i]);
        }
    }

    if (mx == ' ')
        return "";
    else
        return string(3, mx);
}

int main()
{
    string s = "6777133339";
    cout << largestGoodInteger(s);
    return 0;
}