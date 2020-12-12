#include <iostream>
using namespace std;
void leftRotate(int a[], int n)
{

  int temp = a[0];
  for (int i = 1; i < n; i++)
  {
    a[i - 1] = a[i];
  }
  a[n - 1] = temp;
}
int main()
{
  int a[] = {1, 2, 3, 4};
  leftRotate(a, 4);
  for (int i = 0; i < 4; i++)
    cout << a[i] << " ";
  return 0;
}