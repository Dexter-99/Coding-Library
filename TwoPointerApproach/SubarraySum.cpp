#include <iostream>
using namespace std;
// Time Complexity O(n);
void subarraySum(int a[], int n, int s)
{
  int start = 0;
  int end = 0;
  int sum = 0;
  bool flag = false;
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
    while (sum > s)
      sum -= a[start];
    if (sum == s)
    {
      end = i;
      bool flag = false;
      break;
    }
  }
  if (flag)
    cout << start << end << endl;
  else
  {
    cout << -1 << endl;
  }
}
int main()
{
  int a[1] = {1};
  int s = 0;
  subarraySum(a, 1, s);
  return 0;
}