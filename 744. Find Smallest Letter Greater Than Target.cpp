#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{

    for (int i = 0; i < letters.size(); i++)
    {
        if (letters[i] > target)
            return letters[i];

        else
            return letters[0];
    }
}
int main()
{
    char c = 'a';
    cout << c++;
    cout << c++;
    return 0;
}