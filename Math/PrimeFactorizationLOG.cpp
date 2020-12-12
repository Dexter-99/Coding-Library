#include <iostream>
using namespace std;
const int maxN = 1000000;
int a[maxN + 1];
void primeFact(int n)
{
  while (n > 1)
  {
    cout << a[n] << endl;
    n = n / a[n];
  }
}
void sieve()
{
  for (int i = 1; i <= maxN; i++)
    a[i] = i;
  for (int i = 2; i * i <= maxN; i++)
  {
    if (a[i] == i)
      for (int j = i * i; j <= maxN; j += i)
      {
        if (a[j] == j)
          a[j] = i;
      }
  }
}
int main()
{
  int n = 50;
  sieve();
  primeFact(n);
  return 0;
}