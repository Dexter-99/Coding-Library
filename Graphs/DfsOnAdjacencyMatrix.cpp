#include <iostream>
using namespace std;
const int N = 5;
int mat[N][N];
void dfsRec(int n, int s, bool visited[])
{
  cout << s << " ";
  visited[s] = true;
  for (int i = 0; i < n; i++)
  {
    if (mat[s][i] == 1 && (visited[i] == false))
    {
      dfsRec(n, i, visited);
    }
  }
}
int main()
{
  int n = 4;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      mat[i][j] = 0;
    }
  }
  mat[0][1] = 1;
  mat[1][0] = 1;
  mat[0][2] = 1;
  mat[2][0] = 1;
  mat[1][3] = 1;
  mat[3][1] = 1;

  bool visited[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }
  dfsRec(n, 0, visited);
  return 0;
}