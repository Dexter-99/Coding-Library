#include <iostream>
using namespace std;
int subsetSum(int a[], int n, int sum)
{
  int dp[n + 1][sum + 1];
  for (int i = 0; i <= sum; i++)
  {
    dp[0][i] = 0;
  }
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= sum; j++)
    {
      if (j < a[i - 1])
        dp[i][j] = dp[i - 1][j];
      else
      {
        dp[i][j] = dp[i - 1][j - 1] + dp[i][j - a[i - 1]];
      }
    }
  }
  return dp[n][sum];
}
int main()
{
  int n = 3;
  int a[n] = {2, 5, 3};
  int sum = 5;
  cout << subsetSum(a, n, sum) << endl;
  return 0;
}