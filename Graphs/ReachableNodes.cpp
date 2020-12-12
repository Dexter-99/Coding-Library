#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void addEdge(vector<int> list[], int u, int v)
{
  list[u].push_back(v);
  list[v].push_back(u);
}
void bfs(vector<int> adj[], int v, int u)
{
  bool visited[v + 1] = {0};
  queue<int> q;
  visited[u] = 1;
  q.push(u);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    cout << node << endl;
    for (int x : adj[node])
    {
      if (!visited[x])
      {
        visited[x] = 1;
        q.push(x);
      }
    }
  }
}
int main()
{
  int v = 4;
  vector<int> adj[v];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  bfs(adj, v, 0);
  return 0;
}