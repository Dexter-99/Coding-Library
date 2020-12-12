#include <iostream>
using namespace std;
bool isPal(string s, int l, int h)
{
  if (l >= h)
    return true;
  if (s[l] != s[h])
    return false;
  return isPal(s, l + 1, h - 1);
}
int palRecursive(string s, int i, int j)
{
  if (isPal(s, i, j))
    return 0;

  int res = INT32_MAX;
  for (int k = i; k < j; k++)
  {
    res = min(res, 1 + palRecursive(s, i, k) + palRecursive(s, k + 1, j));
  }
  return res;
}
int palDP(string s, int n)
{
  int dp[n][n];
  for (int i = 0; i < n; i++)
    dp[i][i] = 0;
  for (int gap = 1; gap < n; gap++)
  {
    for (int i = 0; i + gap < n; i++)
    {
      int j = i + gap;
      if (isPal(s, i, j))
        dp[i][j] = 0;
      else
      {
        dp[i][j] = INT32_MAX;
        for (int k = i; k < j; k++)
        {
          dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
        }
      }
    }
  }
  return dp[0][n - 1];
}
int main()
{
  string s = "abcdc";
  cout << palRecursive(s, 0, s.length() - 1) << endl;
  cout << palDP(s, s.length()) << endl;
  return 0;
}