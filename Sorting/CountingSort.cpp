#include <iostream>
using namespace std;
// This approach is not a general purpose algorithm i.e. it cannot be used to sort an array of objects
void naive(int a[], int n, int k)
{
  int count[k + 1];
  for (int i = 0; i <= k; i++)
    count[i] = 0;

  for (int i = 0; i < n; i++)
    count[a[i]]++;

  int idx = 0;
  for (int i = 0; i <= k; i++)
  {
    for (int j = 0; j < count[i]; j++)
    {
      a[idx++] = i;
    }
  }
}
// General Purpose Approach
void efficient(int a[], int n, int k)
{
  int count[k + 1];
  for (int i = 0; i <= k; i++)
    count[i] = 0;

  for (int i = 0; i < n; i++)
    count[a[i]]++;

  for (int i = 1; i <= k; i++)
  {
    count[i] = count[i - 1] + count[i];
  }
  int output[n];
  for (int i = n - 1; i >= 0; i--)
  {
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--;
  }
  for (int i = 0; i < n; i++)
    a[i] = output[i];
}
int main()
{
  int n = 6;
  int a[] = {1, 3, 0, 6, 3, 1};
  int k = 6;
  efficient(a, n, k);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}