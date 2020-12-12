#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  //unsorted array or vector
  vector<int> v = {20, 40, 15, 12, 14, 18};
  int x = 12;
  int i;
  for (i = 0; i < v.size(); i++)
  {
    if (v[i] == x)
      break;
  }
  if (i == v.size())
    cout << -1 << endl;
  else
    cout << "Found at " << i << endl;

  // Using  _builtin find() algorithm

  auto it = find(v.begin(), v.end(), x);
  if (it == v.end())
    cout << -1 << endl;
  else
    cout << "Found at " << it - v.begin() << endl;
  
  return 0;
}