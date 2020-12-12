#include <iostream>
using namespace std;
bool isSorted(int a[], int n)
{
  for (int i = 1; i < n; i++)
  {
    if (a[i] < a[i - 1])
      return false;
  }
  return true;
}
int main()
{
  int a[5] = {10, 20, 30, 40, 50};
  cout << isSorted(a, 5) << endl;
}