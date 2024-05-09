#include <bits/stdc++.h>

using namespace std;

// Brute force : T(n)=0(n)

/*
double myPow(double x, int n)
{
    double ans = 1;

    if (n < 0)
    {
        n *= -1;
        long N = n;
        for (double i = 0; i < N; i++)
        {
            ans = ans * x;
        }
        return 1 / ans;
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            ans *= x;
        }

        return ans;
    }
}

*/

//--------------------------------------------------------

// Optimal : T(n) = 0(logn);

double POW(double x, long n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return POW(1 / x, -n);
    if (n % 2 == 0)
        return POW(x * x, n / 2);
    else
    {
        return x * POW(x * x, (n - 1) / 2);
    }
}

double myPow(double x, int n)
{

    return POW(x, n);
}

int main()
{
    return 0;
}