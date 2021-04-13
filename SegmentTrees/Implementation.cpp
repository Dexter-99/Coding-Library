#include <iostream>
using namespace std;
int range_query(int ss, int se, int qs, int qe, int si, int tree[])
{
  if (se < qs || qe < ss)
    return 0;
  if (qs <= ss && qe >= se)
    return tree[si];
  int mid = ss + (se - ss) / 2;
  int l = range_query(ss, mid, qs, qe, 2 * si + 1, tree);
  int r = range_query(mid + 1, se, qs, qe, 2 * si + 2, tree);
  return l + r;
}
void update(int ss, int se, int si, int tree[], int i, int val)
{
  if (ss == se)
  {
    tree[si] = val;
    return;
  }
  int mid = ss + (se - ss) / 2;
  if (i >= ss && i <= mid)
    update(ss, mid, 2 * si + 1, tree, i, val);
  else
    update(mid + 1, se, 2 * si + 2, tree, i, val);
  tree[si] = tree[2 * si + 1] + tree[2 * si + 2];
}
void build(int ss, int se, int si, int tree[], int a[])
{
  if (ss == se)
  {
    tree[si] = a[ss];
    return;
  }
  int mid = ss + (se - ss) / 2;
  build(ss, mid, 2 * si + 1, tree, a);
  build(mid + 1, se, 2 * si + 2, tree, a);
  tree[si] = tree[2 * si + 1] + tree[2 * si + 2];
}
int main()
{
  int n = 6;
  int a[n] = {1, 5, 2, -3, 4, -1};
  int tree[4 * n + 4];
  build(0, n - 1, 0, tree, a);
  cout << range_query(0, n - 1, 0, 3, 0, tree) << endl;
  update(0, n - 1, 0, tree, 2, 1);
  cout << range_query(0, n - 1, 0, 3, 0, tree) << endl;
  return 0;
}