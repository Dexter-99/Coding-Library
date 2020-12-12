#include <bits/stdc++.h>
using namespace std;
int getDpCount(int coins[], int sum, int n)
{
  int dp[sum + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int i = 1; i <= sum; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i >= coins[j])
        dp[i] = (dp[i] + dp[i - coins[j]]);
    }
  }
  return dp[sum];
}
int main()
{
  int n, x;
  x = 3;
  n = 6;
  int a[n] = {1, 2, 3, 4, 5, 6};
  cout << getDpCount(a, x, n) << endl;
  return 0;
}
