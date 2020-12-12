#include <iostream>
using namespace std;
void insert(int x, int pos, int cap, int n, int a[])
{
  if (n == cap)
    return;
  int idx = pos - 1;
  for (int i = n - 1; i >= idx; i--)
  {
    a[i + 1] = a[i];
  }
  a[idx] = x;
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
  int a[5] = {5, 10, 20, 0, 0};
  print(a, 3);
  insert(7, 2, 5, 3, a);
  print(a, 4);
}