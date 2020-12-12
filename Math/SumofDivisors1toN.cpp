#include <iostream>
#define ll long long
#define MOD 1000000007
using namespace std;
ll sum(ll n)
{
  return (n * (n + 1) / 2) % MOD;
}
ll rangeSum(ll a, ll b)
{
  return (sum(b) - sum(a)) % MOD;
}
ll result(ll n)
{
  ll res = 0;
  ll i = 1;
  while (1)
  {
    res = (res + (rangeSum(n / (i + 1), n / i)) * (i % MOD)) % MOD;
    if (i == n)
      break;
    i = n / (n / (i + 1));
  }
  cout << res << endl;
}
int main()
{
  ll n = 5;
  result(n);
  return 0;
}