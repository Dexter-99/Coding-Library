#include <iostream>
using namespace std;
int sqrRoot(int n)
{
  int low = 1, high = n, ans = 0;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int sqr = mid * mid;
    if (sqr <= n)
    {
      low = mid + 1;
      ans = mid;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
}
int main()
{
  int a = 14;
  int b = 36;
  cout << sqrRoot(a) << endl;
  cout << sqrRoot(b) << endl;
  return 0;
}