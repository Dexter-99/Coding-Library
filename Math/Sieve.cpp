#include <iostream>
using namespace std;
const int maxN = 1e6;
bool prime[maxN + 1];
void sieve()
{
  prime[0] = prime[1] = 1;
  for (int i = 2; i * i <= maxN; i++)
  {
    if (!prime[i])
    {
      for (int j = i * i; j <= maxN; j += i)
      {
        prime[j] = 1;
      }
    }
  }
}