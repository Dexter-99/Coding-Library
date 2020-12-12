#include <iostream>
using namespace std;
#define fo(i, n) for (int i = 1; i <= n; i++)
#define N 101
int A[N][N], I[N][N];
void mul(int mat1[][N], int mat2[][N], int dim)
{
  int C[dim + 1][dim + 1];
  for (int i = 1; i <= dim; i++)
  {
    for (int j = 1; j <= dim; j++)
    {
      C[i][j] = 0;
      for (int k = 1; k <= dim; k++)
        C[i][j] += (mat1[i][k] * mat2[k][j]);
    }
  }
  for (int i = 1; i <= dim; i++)
    for (int j = 1; j <= dim; j++)
      mat1[i][j] = C[i][j];
}
void power(int n, int dim)
{
  fo(i, dim) fo(j, dim) cin >> A[i][j];
  fo(i, dim)
      fo(j, dim)
  {
    if (i == j)
      I[i][j] = 1;
    else
      I[i][j] = 0;
  }
  while (n > 0)
  {
    if (n & 1)
      mul(I, A, dim);
    mul(A, A, dim);
    n >>= 1;
  }
  for (int i = 1; i <= dim; i++)
  {
    for (int j = 1; j <= dim; j++)
    {
      cout << I[i][j] << " ";
    }
    cout << endl;
  }
}
int main()
{
  int n, dim;
  cin >> dim >> n;
  power(n, dim);
  return 0;
}