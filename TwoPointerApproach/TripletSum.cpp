#include <iostream>
using namespace std;
bool isPair(int a[], int low, int high, int target)
{
  while (low < high)
  {
    if (a[low] + a[high] == target)
    {
      return true;
    }
    else if (a[low] + a[high] > target)
      high--;
    else
      low++;
  }
  return false;
}
int main()
{
  int n = 8;
  int a[n] = {1, 2, 3, 4, 5, 6, 7, 8};
  int target = 13;
  for (int i = 0; i < n - 2; i++)
  {
    if (isPair(a, i + 1, n - 1, target - a[i]))
    {
      cout << true << endl;
      break;
    }
  }
  return 0;
}