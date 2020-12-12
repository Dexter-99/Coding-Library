#include <iostream>
using namespace std;
int lisFunc(int a[], int n)
{
  int lis[n];
  lis[0] = 1;
  for (int i = 1; i < n; i++)
  {
    lis[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if (a[j] < a[i])
        lis[i] = max(lis[i], lis[j] + 1);
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    res = max(res, lis[i]);
  }
  return res;
}
int main()
{
  int n = 7;
  int a[n] = {3, 4, 2, 8, 5, 10, 1};
  cout << lisFunc(a, n) << endl;

  return 0;
}