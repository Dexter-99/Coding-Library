#include <iostream>
using namespace std;
// O(n) approach for each query
int naive(int a[], int l, int r)
{
  int sum = 0;
  for (int i = l; i <= r; i++)
  {
    sum += a[i];
  }
  return sum;
}
// Precomputation for prefix array O(n);
// query processing O(1);
int efficient(int a[], int l, int r, int n)
{
  int pre[n] = {0};
  pre[0] = a[0];
  for (int i = 1; i < n; i++)
  {
    pre[i] = pre[i - 1] + a[i];
  }
  if (l == 0)
    return a[r];
  else
    return pre[r] - pre[l - 1];
}
int main()
{
  int n = 7;
  int a[n] = {2, 8, 3, 9, 6, 5, 4};
  cout << naive(a, 0, 2) << endl;
  cout << efficient(a, 1, 3, n) << endl;
  cout << efficient(a, 2, 6, n) << endl;
  return 0;
}