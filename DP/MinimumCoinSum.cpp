#include <iostream>
using namespace std;
int main()
{
  int x = 10;
  int n = 3;
  int a[n] = {1, 3, 4};
  int dp[x + 1];
  for (int i = 0; i <= x; i++)
    dp[i] = INT32_MAX;
  dp[0] = 0;
  for (int i = 1; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (a[j] <= i)
        dp[i] = min(dp[i], dp[i - a[j]] + 1);
    }
  }
  cout << dp[x] << endl;
}