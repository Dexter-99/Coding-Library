#include <iostream>
using namespace std;
int _delete(int x, int n, int a[])
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (a[i] == x)
      break;
  }
  if (i == n)
    return n;
  else
  {
    for (int j = i; j < n - 1; j++)
    {
      a[j] = a[j + 1];
    }
  }
  return n - 1;
}
void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main()
{
  int a[5] = {5, 10, 20, 5, 15};
  print(a, 5);
  int n = _delete(10, 5, a);
  print(a, n);
}