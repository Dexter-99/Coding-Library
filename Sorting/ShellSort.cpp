#include <iostream>
#include <cmath>
using namespace std;
void shellSort(int a[], int n)
{
  for (int gap = floor(n / 2); gap > 0; gap =gap / 2)
  {
    for (int i = gap; i < n; i++)
    {
      int temp = a[i];
      int j = i;
      while (j >= gap && a[j-gap] > temp)
      {
        a[j] = a[j - gap];
        j-=gap;
      }
      a[j] = temp;
    }
  }
}
int main()
{
  int n = 5;
  int a[n] = {12, 34, 54, 2, 3};
  shellSort(a, n);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}