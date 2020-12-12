#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(vector<int> adj[], int i, int j, int n, int m)
{
  if (i < 0 || i >= n || j < 0 || j >= m || adj[i][j] != 1)
    return false;
  return true;
}
void bfs(vector<int> adj[], int i, int j, int n, int m)
{
  queue<pair<int, int>> q;
  q.push({i, j});
  adj[i][j] = 2;
  int row[8] = {-1, -1, 1, 1, 1, 0, -1, 0};
  int col[8] = {-1, 1, -1, 1, 0, 1, 0, -1};
  while (!q.empty())
  {
    int currI = q.front().first;
    int currJ = q.front().second;
    q.pop();
    for (int k = 0; k < 8; k++)
    {
      if (check(adj, currI + row[k], currJ + col[k], n, m))
      {
        q.push({currI + row[k], currJ + col[k]});
        adj[currI + row[k]][currJ + col[k]] = 2;
      }
    }
  }
}
int findIslands(vector<int> a[], int n, int m)
{

  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == 1)
      {
        bfs(a, i, j, n, m);
        count++;
      }
    }
  }
  return count;
  // Your code here
}