#include <iostream>
using namespace std;
int main()
{
  string s1 = "ABCDGH";
  string s2 = "AEDKH";
  int m = s1.length();
  int n = s2.length();
  int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      dp[i][j] = -1;
    }
  }
  for (int i = 0; i <= n; i++)
    dp[0][i] = 0;
  for (int i = 0; i <= m; i++)
    dp[i][0] = 0;

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (dp[i][j] == -1)
      {
        string st1 = s1.substr(0, i);
        string st2 = s2.substr(0, j);
        if (st1[i - 1] == st2[j - 1])
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
  }
  cout << dp[m][n] << endl;

  return 0;
}