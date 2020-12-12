#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void addEdge(vector<int> list[], int u, int v)
{
  list[u].push_back(v);
  list[v].push_back(u);
}
bool bipartite(vector<int> adj[], int v, int s)
{
  int color[v];
  for (int i = 0; i < v; i++)
    color[i] = -1;
  queue<int> q;
  color[s] = 1;
  q.push(s);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (int x : adj[node])
    {
      if (color[x] == -1)
      {
        color[x] = 1 - color[node];
        q.push(x);
      }
      else if (color[x] == color[node])
        return false;
    }
  }
  return true;
}
int main()
{
  int v = 6;
  vector<int> adj[v];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 5);
  addEdge(adj, 5, 0);
  cout << bipartite(adj, v, 0) << endl;
  return 0;
}