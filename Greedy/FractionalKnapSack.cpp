#include <iostream>
#include <algorithm>
using namespace std;
double fracKnap(pair<int, int> a[], int n, int W)
{
  sort(a, a + n, [](pair<int, int> p1, pair<int, int> p2) {
    double r1 = p1.second / (double)p1.first;
    double r2 = p2.second / (double)p2.first;
    return r1> r2;
  });
  double res = 0.0;
  int curr = W;
  for (int i = 0; i < n; i++)
  {
    if (a[i].first <= curr)
    {
      res += a[i].second;
      curr -= a[i].first;
    }
    else
    {
      res += a[i].second * (curr / (double)a[i].first);
      return res;
    }
  }
  return res;
}
int main()
{
  int n = 3;
  pair<int, int> a[n] = {
      {50, 600},
      {20, 500},
      {30, 400},
  };
  int W = 70;
  cout << fracKnap(a, n, W);
  return 0;
}