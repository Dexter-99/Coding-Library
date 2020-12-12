#include <iostream>
using namespace std;
int findMed(int a1[], int n1, int a2[], int n2)
{
  int low = 0, high = n1;
  while (low <= high)
  {
    int i1 = (low + high) / 2;
    int i2 = (n1 + n2 + 1) / 2 - i1;
    int min1 = (i1 == n1) ? INT32_MAX : a1[i1];
    int max1 = (i1 == 0) ? INT32_MIN : a1[i1 - 1];
    int min2 = (i2 == n2) ? INT32_MAX : a2[i2];
    int max2 = (i2 == 0) ? INT32_MIN : a2[i2 - 1];
    if (max1 <= min2 && max2 <= min1)
    {
      if ((n1 + n2) % 2 == 0)
        return (max(max1, max2) + min(min1, min2)) / 2;
      else
        return max(max1, max2);
    }
    else if (max1 > min2)
      high = i1 - 1;
    else
      low = i1 + 1;
  }
}
int main()
{
  int n1 = 5;
  int a[n1] = {1, 2, 3, 4, 5};
  int n2 = 6;
  int b[n2] = {3, 4, 5, 6, 7, 8};
  if (n1 <= n2)
    cout << findMed(a, n1, b, n2) << endl;
  else
    cout << findMed(b, n2, a, n1) << endl;
  return 0;
}