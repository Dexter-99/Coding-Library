// If we are given an infinite
// sorted array like [1,10,15,20,40,60,80,100,200,......]
// and we have to find an element
// then normal binary search wont work;
using namespace std;
int seatch(int a[], int x)
{
  int i = 0;
  if (a[i] == x)
    return i;
  while (a[i] < x)
  {
    i *= 2;
  }
  if (a[i] == x)
    return i;
  // else
  // binarySearch(a, i / 2 + 1, i - 1, x);
}
int main()
{
  int a[9] = {1, 10, 15, 20, 40, 60, 80, 100, 200};

  return 0;
}