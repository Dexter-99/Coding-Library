#include <iostream>
using namespace std;
int naive(int v[], int w[], int n, int W)
{
  if (n == 0 || W == 0)
    return 0;
  if (w[n - 1] > W)
  {
    return naive(v, w, n - 1, W);
  }
  return max(naive(v, w, n - 1, W), v[n - 1] + naive(v, w, n - 1, W - w[n - 1]));
}
int efficient(int v[], int w[], int n, int W)
{
  int dp[n + 1][W + 1];
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= W; i++)
  {
    dp[0][i] = 0;
  }
  int res = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      if (w[i - 1] > j)
      {
        dp[i][j] = dp[i - 1][j];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], v[i-1] + dp[i - 1][j - w[i - 1]]);
      }
    }
  }
  return dp[n][W];
}
int main()
{
  int n = 4;
  int v[] = {10, 40, 30, 50};
  int w[] = {5, 4, 6, 3};
  int W = 10;
  cout << naive(v, w, n, W) << endl;
  cout << efficient(v, w, n, W) << endl;
  ;
  return 0;
}