#include <iostream>
using namespace std;
int naive(int a[], int start, int end)
{
  if (end <= start)
    return 0;
  int profit = 0;
  for (int i = start; i < end; i++)
  {
    for (int j = i + 1; j <= end; j++)
    {
      if (a[j] > a[i])
      {
        int maxProfit = a[j] - a[i] + naive(a, start, i - 1) + naive(a, j, end);
        profit = max(profit, maxProfit);
      }
    }
  }
  return profit;
}
int efficient(int a[], int n)
{
  int profit = 0;
  for (int i = 1; i < n; i++)
  {
    if (a[i] > a[i - 1])
    {
      profit += a[i] - a[i - 1];
    }
  }
  return profit;
}
int main()
{
  int a[5] = {1, 5, 3, 8, 12};
  cout << naive(a, 0, 4) << endl;
  cout << efficient(a, 5) << endl;
  return 0;
}