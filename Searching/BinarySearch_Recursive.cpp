#include <iostream>
#include <algorithm>
using namespace std;
// O(log n) Auxillary Space
// O(log n) Time
int binarySearch(int *a, int low, int high, int x)
{
  if (low > high)
    return -1;

  int mid = low + (high - low) / 2;
  if (a[mid] == x)
    return mid;
  else if (x > a[mid])
    return binarySearch(a, mid + 1, high, x);
  else
    return binarySearch(a, low, mid - 1, x);
}
int main()
{
  int a[7] = {10, 20, 30, 40, 50, 60, 70};
  int x = 60;
  cout << binarySearch(a, 0, 6, x) << endl;

  //Using Builtin binary_search() stl algorithm
  cout << binary_search(a, a + 7, x);
  return 0;
}