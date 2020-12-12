#include <iostream>
using namespace std;
int maxDiff(int a[], int n)
{
  int minVal = a[0];
  int _max = a[1] - a[0];
  for (int j = 1; j < n; j++)
  {
    _max = max(_max, a[j] - minVal);
    minVal = min(minVal, a[j]);
  }
  return _max;
}
int main()
{
  int a[4] = {3, 6, 9, 1} ;cout << maxDiff(a, 4) << endl;
}