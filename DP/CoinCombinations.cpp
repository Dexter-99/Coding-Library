#include <iostream>
using namespace std;
int countComb(int coins[], int sum, int n)
{
  if (sum == 0)
    return 1;
  if (n == 0)
    return 0;
  int res = countComb(coins, sum, n - 1);
  if (coins[n - 1] <= sum)
    res = res + countComb(coins, sum - coins[n - 1], n);
  return res;
}
int getDpCount(int coins[], int sum, int n)
{
  int dp[sum + 1][n + 1];
  for (int i = 0; i <= sum; i++)
    dp[i][0] = 0;
  for (int i = 0; i <= n; i++)
    dp[0][i] = 1;
  for (int i = 1; i <= sum; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      dp[i][j] = dp[i][j - 1];
      if (coins[j - 1] <= i)
      {
        dp[i][j] += dp[i - coins[j - 1]][j];
      }
    }
  }
  return dp[sum][n];
}
int getDpCount2(int coins[], int sum, int n)
{
  int dp[sum + 1] = {0};
  dp[0] = 1;
    for (int j = 0; j < n; j++)
  {
  for (int i = 1; i <= sum; i++)
    {
      if (coins[j] <= i)
        dp[i] += dp[i - coins[j]];
    }
  }
  return dp[sum];
}
int main()
{
  int n = 6;
  int coins[n] = {1, 2, 3, 4, 5, 6};
  int sum = 3;
  cout << countComb(coins, sum, n) << endl;
  cout << getDpCount(coins, sum, n) << endl;
  cout << getDpCount2(coins, sum, n) << endl;
  return 0;
}