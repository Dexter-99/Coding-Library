#include <iostream>
#include <queue>
using namespace std;
const int N = 5;
int mat[N][N];
void bfs(int n, int s, bool visited[])
{
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while (!q.empty())
  {
    int curr = q.front();
    cout << curr << " ";
    q.pop();
    for (int i = 0; i < n; i++)
    {
      if (mat[curr][i] == 1 && (visited[i] == false))
      {
        q.push(i);
        visited[i] = true;
      }
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
  bfs(n, 0, visited);
  return 0;
}