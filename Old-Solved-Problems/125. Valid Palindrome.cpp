#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{

    string clean;

    for (auto it : s)
    {
        if (isalnum(it))
            clean += tolower(it);
    }
    string original = clean;
    reverse(clean.begin(), clean.end());

    if (original == clean)
        return true;
    else
        return false;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);
    return 0;
}