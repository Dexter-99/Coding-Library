#include <iostream>
using namespace std;
int naive(int a[], int n)
{
  int res = 0;
  for (int i = 1; i < n - 1; i++)
  {
    int lmax = a[i], rmax = a[i];
    for (int j = 0; j < i; j++)
      lmax = max(lmax, a[j]);
    for (int j = i + 1; j < n; j++)
      rmax = max(rmax, a[j]);
    res += min(lmax, rmax) - a[i];
  }
  return res;
}
int main()
{
  int a[5] = {5, 4, 3, 2, 1};
  cout << naive(a, 5) << endl;
  return 0;
}