#include <iostream>
#include <cmath>
using namespace std;
void insertionSort(int a[], int n)
{

  for (int i = 1; i < n; i++)
  {
    int temp = a[i];
    int j = i;
    while (j >= 1 && a[j - 1] > temp)
    {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = temp;
  }
}
int main()
{
  int n = 5;
  int a[n] = {12, 34, 54, 2, 3};
  insertionSort(a, n);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}