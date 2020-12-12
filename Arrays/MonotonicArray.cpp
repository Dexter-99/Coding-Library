#include <iostream>
using namespace std;
bool isMonotonic(int A[], int n)
{
  bool inc = true;
  bool dec = true;
  for (int i = 0; i < n - 1; i++)
  {
    if (A[i] > A[i + 1])
      inc = false;
    if (A[i] < A[i + 1])
      dec = false;
  }

  return inc || dec;
}
int main()
{

  return 0;
}