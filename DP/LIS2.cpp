#include <iostream>
#include <algorithm>
using namespace std;
int lis(int a[], int n)
{
  int tail[n];
  tail[0] = a[0];
  int len = 1;
  for (int i = 1; i < n; i++)
  {
    if (a[i] > tail[len - 1])
    {
      tail[len] = a[i];
      len++;
    }
    else
    {
      auto it = upper_bound(tail, tail + len, a[i]);
      int idx = it - tail;
      tail[idx] = a[i];
    }
  }
  for (int i = 0; i < len; i++)
    cout << tail[i] << endl;
  return len;
}
int main()
{
  int n = 8;
  int a[n] = {7, 3, 5, 3, 6, 2, 9, 8};
  cout << lis(a, n) << endl;
  return 0;
}