#include <iostream>
#include <cmath>
#define ll long long
#define maxN 1000001
const int MOD = 1e9 + 7;
using namespace std;
// Binet's Formula
// f(n)=((1+sqrt(5))^n-(1-sqrt(5))^n)/(2^n*sqrt(5));
// f(0)=0
// f(1)=1
int main()
{
  int n;
  cin >> n;
  double val = (pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n)) / (pow(2, n) * sqrt(5));
  cout << val << endl;
  return 0;
}