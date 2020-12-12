#include <iostream>
using namespace std;
bool checkPair(int a[], int n, int x)
{
  int low = 0;
  int high = n - 1;
  while (low < high)
  {
    if (a[low] + a[high] == x)
      return true;
    else if (a[low] + a[high] > x)
      high--;
    else
      low++;
  }
  return false;
}
int main()
{
  int a[8] = {2, 4, 8, 9, 11, 12, 20, 30};
  int target = 23;
  cout << checkPair(a, 8, target) << endl;
  return 0;
}