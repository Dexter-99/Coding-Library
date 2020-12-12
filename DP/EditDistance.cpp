#include <iostream>
using namespace std;
int editDist(string s1, string s2, int m, int n)
{
  if (m == 0)
    return n;
  if (n == 0)
    return m;
  if (s1[m - 1] == s2[n - 1])
    return editDist(s1, s2, m - 1, n - 1);
  else
  {
    return 1 + min(editDist(s1, s2, m - 1, n), min(editDist(s1, s2, m, n - 1), editDist(s1, s2, m - 1, n - 1)));
  }
}
int editDistDP(string s1, string s2, int m, int n)
{
  int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    dp[i][0] = i;
  for (int i = 0; i <= n; i++)
    dp[0][i] = i;
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
      {
        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
      }
    }
  }
  return dp[m][n];
}

int main()
{
  string s1 = "SATURDAY";
  string s2 = "SUNDAY";
  cout << editDist(s1, s2, s1.length(), s2.length()) << endl;
  cout << editDistDP(s1, s2, s1.length(), s2.length()) << endl;
  return 0;
}