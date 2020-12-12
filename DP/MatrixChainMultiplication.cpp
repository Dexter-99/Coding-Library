#include <iostream>
using namespace std;
int matRecursive(int a[], int i, int j)
{
  if ((i + 1) == j)
    return 0;

  int res = INT32_MAX;
  for (int k = i + 1; k < j; k++)
  {
    res = min(res, matRecursive(a, i, k) + matRecursive(a, k, j) + a[i] * a[j] * a[k]);
  }
  return res;
}
int matDP(int a[], int n)
{
  int dp[n][n];
  for (int i = 0; i < n - 1; i++)
    dp[i][i + 1] = 0;
  for (int gap = 2; gap < n; gap++)
  {
    for (int i = 0; i + gap < n; i++)
    {
      int j = i + gap;
      dp[i][j] = INT32_MAX;
      for (int k = i + 1; k < j; k++)
      {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
      }
    }
  }
  return dp[0][n - 1];
}
int main()
{
  int a[4] = {2, 1, 3, 4};
  cout << matRecursive(a, 0, 3) << endl;
  cout << matDP(a, 4) << endl;
  return 0;
}