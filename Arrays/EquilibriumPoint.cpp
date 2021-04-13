#include <iostream>
using namespace std;
bool equilibrium(int a[], int n)
{
  int pre[n] = {0};
  int suff[n] = {0};
  pre[0] = a[0];
  for (int i = 1; i < n; i++)
  {
    pre[i] = pre[i - 1] + a[i];
  }
  suff[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    suff[i] = suff[i + 1] + a[i];
  }
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      if (suff[i + 1] == 0)
        return true;
    }
    else if (i == n - 1)
    {
      if (pre[i + 1] == 0)
        return true;
    }
    else
    {
      if (pre[i - 1] == suff[i + 1])
        return true;
    }
  }
  return false;
}
int main()
{
  int n = 6;
  int a[n] = {3, 4, 8, -9, 20, 6};
  cout << equilibrium(a,n) << endl;
  return 0;
}