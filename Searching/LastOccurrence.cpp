#include <iostream>
using namespace std;
int lastOccurrence(int a[], int n, int x)
{
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (a[mid] == x && (mid == n - 1 || a[mid + 1] != x))
    {
      return mid;
    }
    else if (x >= a[mid])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}
int main()
{
  int a[7] = {5, 10, 10, 15, 20, 20, 20};
  int x = 20;
  cout << lastOccurrence(a, 7, 10) << endl;
  ;
  return 0;
}