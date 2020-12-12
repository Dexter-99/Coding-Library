#include <iostream>
using namespace std;
int remove(int a[], int n)
{
  int res = 1;
  for (int i = 1; i < n; i++)
  {
    if (a[res - 1] != a[i])
    {
      a[res] = a[i];
      res++;
    }
  }
  return res;
}
int main()
{
  int a[7] = {10, 20, 20, 30, 30, 30, 30};
  int res = remove(a, 7);
  for (int i = 0; i < res; i++)
    cout << a[i] << "  ";
  return 0;
}