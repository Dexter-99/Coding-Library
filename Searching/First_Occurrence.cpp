#include <iostream>
#include <algorithm>
using namespace std;
int builtin_func(int a[], int n, int x)
{
  auto it = lower_bound(a, a + n, x);
  if (it == a + n || *it != x)
    return -1;
  else
  {
    return it - a;
  }
}
int firstOccurrence(int a[], int n, int x)
{
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (a[mid] == x && (mid == 0 || a[mid - 1] != x))
      return mid;
    else if (x <= a[mid])
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return -1;
}
int main()
{
  int a[7] = {5, 10, 10, 15, 20, 20, 20};
  int x = 20;
  cout << builtin_func(a, 7, 20) << endl;
  cout << firstOccurrence(a, 7, 20) << endl;
  ;
  return 0;
}