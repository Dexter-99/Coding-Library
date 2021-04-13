#include <iostream>
using namespace std;
int frequentElement(int l[], int r[], int n)
{
  // or the maximum 'R' that is possible;
  int arr[1000] = {0 };
  for (int i = 0; i < n; i++)
  {
    arr[l[i]]++;
    arr[r[i] + 1]--;
  }
  int prev[1000];
  prev[0] = 0;
  for (int i = 1; i < 1000; i++)
  {
    prev[i] = prev[i - 1] + arr[i];
  }
  int res = prev[0], idx = 0;
  for (int i = 1; i < 1000; i++)
  {
    if (prev[i] > res)
    {
      res = prev[i];
      idx = i;
    }
  }
  return idx;
}
int main()
{
  int n = 3;
  int l[n] = {1, 2, 5};
  int r[n] = {5, 8, 7};
  cout << frequentElement(l, r, n) << endl;
  return 0;
}