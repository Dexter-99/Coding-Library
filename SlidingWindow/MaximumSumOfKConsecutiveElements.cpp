#include <iostream>
using namespace std;
int maxK(int a[], int n, int k)
{
  int slow = 0;
  int high = k - 1;
  int _max = 0;
  int _sum = 0;
  for (int i = slow; i <= high; i++)
  {
    _sum += a[i];
  }
  _max = _sum;
  while (high < n)
  {
    _sum += a[++high];
    _sum -= a[--slow];
    _max = max(_max, _sum);
  }
  return _max;
}
int main()
{
  int n = 6;
  int a[n] = {1, 8, 30, -5, 20, 7};
  int k = 3;
  cout << maxK(a, n, k) << endl;
  return 0;
}