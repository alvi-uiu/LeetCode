#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

// Brute force : T=> O(n^2) ; S->0(1)

int maxProfit(vector<int> &prices)
{

  int n = prices.size();
  int profit = 0;
  int MaxProfit = 0;
  for (int i = 0; i < n; i++)
  {

    for (int j = i + 1; j < n; j++)
    {
      if (prices[j] > prices[i])
      {
        profit = prices[j] - prices[i];
        MaxProfit = max(MaxProfit, profit);
      }
    }
  }

  return MaxProfit;
}

//-----------------------------------------------------

// Optimal : T=> O(n) ; S->0(1)

int maxProfit(vector<int> &prices)
{
  int n = prices.size();
  int minBuyingPrice = INT_MAX;
  int maxProfit = 0;
  for (int i = 0; i < n; i++)
  {
    minBuyingPrice = min(minBuyingPrice, prices[i]);

    if (prices[i] > minBuyingPrice)
    {
      int cur_profit = prices[i] - minBuyingPrice;
      maxProfit = max(maxProfit, cur_profit);
    }
  }

  return maxProfit;
}

int main()
{

  vector<int> prices;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    prices.push_back(k);
  }

  maxProfit(prices);

  return 0;
}