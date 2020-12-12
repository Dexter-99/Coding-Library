#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
vector<int> primes;
//=======================
void sieve()
{
  bool prime[maxN + 1];
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= maxN; i++)
  {
    if (prime[i])
    {
      for (int j = i * i; j <= maxN; j += i)
      {
        prime[j] = false;
      }
    }
  }
  for (int i = 2; i <= maxN; i++)
  {
    if (prime[i])
      primes.PB(i);
  }
}
void segSieve(ll l, ll r)
{
  sieve();
  bool isPrime[r - l + 1];
  for (int i = 0; i <= r - l; i++)
    isPrime[i] = true;
  if (l == 1)
    isPrime[0] = false;
  for (int i = 0; primes.at(i) * primes.at(i) <= r; i++)
  {
    int currPrime = primes.at(i);
    ll base = (l / currPrime) * currPrime;
    if (base < l)
      base += currPrime;
    for (ll j = base; j <= r; j += currPrime)
    {
      isPrime[j - l] = false;
    }
    if (base == currPrime)
      isPrime[base - l] = true;
  }
  for (int i = 0; i <= r - l; i++)
  {
    if (isPrime[i])
      cout << i + l << endl;
  }
}