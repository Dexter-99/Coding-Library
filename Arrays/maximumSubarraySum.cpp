#include <iostream>
using namespace std;
int maxSubArray(int nums[], int n)
{
  int maxSub = nums[0];
  int res = nums[0];
  for (int i = 1; i < n; i++)
  {
    maxSub = max(maxSub + nums[i], nums[i]);
    res = max(maxSub, res);
  }
  return res;
}
int main()
{
  return 0;
}