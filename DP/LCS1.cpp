#include <iostream>
using namespace std;
int memo[100][100];
int lcs(string s1, string s2, int m, int n)
{
  // cout << memo[m][n] << endl;
  if (memo[m][n] != -1)
  {
    return memo[m][n];
  }
  if (m == 0 || n == 0)
  {
    memo[m][n] = 0;
  }
  else
  {
    if (s1[m - 1] == s2[n - 1])
    {
      memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
    }
    else
    {
      memo[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
  }
    return memo[m][n];
}
int main()
{
  string s1 = "ABCDGH";
  string s2 = "AEDFHR";
  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < 100; j++)
    {
      memo[i][j] = -1;
    }
  }
  cout << lcs(s1, s2, s1.length(), s2.length()) << endl;
  return 0;
}