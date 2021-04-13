#include <iostream>
using namespace std;
int efficient(int a[], int n)
{
  int res = a[0];
  int maxEnd = a[0];
  for (int i = 1; i < n; i++)
  {
    maxEnd = max(maxEnd + a[i], a[i]);
    res = max(res, maxEnd);
  }
  return res;
}
int naive(int a[], int n)
{
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += a[j];
      res = max(res, sum);
    }
  }
  return res;
}
int main()
{
  int n = 5;
  int a[n] = {1, -2, 3, -1, 2};
  cout << naive(a, n) << endl;
  cout << efficient(a, n) << endl;
  return 0;
}