#include <iostream>
using namespace std;
void freq(int a[], int n)
{
  int f = 1, i = 1;
  while (i < n)
  {
    while (i < n && a[i] == a[i - 1])
    {
      f++;
      i++;
    }
    cout << a[i - 1] << " " << f << endl;
    f = 1;
    i++;
  }
  // if (f == 1)
  //   cout << a[i - 1] << " " << f << endl;
}
int main()
{
  int a[6] = {10, 10, 20, 20, 40, 40};
  freq(a, 6);
  return 0;
}