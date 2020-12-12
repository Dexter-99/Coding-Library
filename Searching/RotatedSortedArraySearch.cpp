#include <iostream>
using namespace std;
int search(int a[], int n, int x)
{
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (a[mid] == x)
      return mid;
    if (a[low] <= a[mid])
    {
      if (x >= a[low] && x < a[mid])
        high = mid - 1;
      else
        low = mid + 1;
    }
    else
    {
      if (x > a[mid] && x <= a[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  return -1;
}
int main()
{
  int a[2] = {3, 1};
  int x = 1;
  cout << search(a, 2, x) << endl;
  return 0;
}