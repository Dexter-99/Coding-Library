#include <iostream>
using namespace std;
int efficient(int a[], int n)
{
  int res = 1;
  int count = 1;
  for (int i = 1; i < n; i++)
  {
    if (((a[i] & 1) && (!(a[i - 1] & 1))) || (!(a[i] & 1) && (a[i - 1] & 1)))
      count++;
    else
    {
      count = 1;
    }
    res = max(res, count);
  }
  return res;
}
int naive(int a[], int n)
{
  int res = 1;
  for (int i = 0; i < n; i++)
  {
    int count = 1;
    for (int j = i + 1; j < n; j++)
    {
      if (((a[j] & 1) && (!(a[j - 1] & 1))) || (!(a[j] & 1) && (a[j - 1] & 1)))
      {
        count++;
    res = max(count, res);
      }
      else
        break;
    }
  }
  return res;
}
int main()
{
  int n = 5;
  int a[n] = {10, 12, 14, 7, 8};
  cout << naive(a, n) << endl;
  cout << efficient(a, n) << endl;
  return 0;
}