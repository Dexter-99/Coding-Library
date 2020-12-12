#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
  a = a ^ b;
  b = b ^ a;
  a = a ^ b;
}
void reverse(int a[], int n)
{

  int low = 0;
  int high = n - 1;
  while (low < high)
  {
    swap(a[low], a[high]);
    low++;
    high--;
  }
}
int main()
{
  int a[5] = {10, 20, 30, 40, 50};
  reverse(a, 5);
  for (int i = 0; i < 5; i++)
    cout << a[i] << " ";
}