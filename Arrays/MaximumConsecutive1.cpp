#include <iostream>
using namespace std;
int maxCount(int a[], int n)
{
  int res = 0;
  int curr = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i])
      curr++;
    else
    {
      res = max(curr, res);
      curr = 0;
    }
  }
  return res;
}
int main()
{
  int a[6] = {0, 1, 1, 0, 1, 0};
  cout << maxCount(a, 6) << endl;
  return 0;
}