#include <iostream>
#include <vector>
using namespace std;
void leader(int a[], int n)
{
  vector<int> v;
  int curr_ldr = a[n - 1];
  v.push_back(curr_ldr);
  for (int i = n - 2; i >= 0; i--)
  {
    if (curr_ldr < a[i])
    {
      curr_ldr = a[i];
      v.push_back(curr_ldr);
    }
  }
  for (int i = v.size() - 1; i >= 0; i--)
  {
    cout << v[i] << " ";
  }
}
int main()
{
  int a[7] = {7, 10, 4, 10, 6, 5, 2};
  leader(a, 7);
  return 0;
}