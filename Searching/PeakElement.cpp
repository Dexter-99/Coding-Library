#include <iostream>
using namespace std;
int naive(int a[], int n)
{
  if (n == 1)
    return a[0];
  if (a[0] >= a[1])
    return a[0];
  if (a[n - 1] >= a[n - 2])
    return a[n - 1];
  for (int i = 1; i < n - 1; i++)
  {
    if (a[i] >= a[i - 1] && a[i] >= a[i + 1])
      return a[i];
  }
  return -1;
}
int efficient(int a[], int n)
{
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if ((mid == 0 || a[mid - 1] <= a[mid]) && (mid == n - 1 || a[mid + 1] <= a[mid]))
      return a[mid];
    else if (mid > 0 && a[mid - 1] > a[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
}
int main()
{
  int a[5] = {5, 7, 4, 20, 12};
  cout << naive(a, 5) << endl;
  cout << efficient(a, 5) << endl;
  return 0;
}