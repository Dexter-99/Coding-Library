#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> list[], int u, int v)
{
  list[u].push_back(v);
  list[v].push_back(u);
}
void DFS(vector<int> adj[], int s, bool visited[], int v)
{
  visited[s] = true;
  cout << s << " ";
  for (int u : adj[s])
  {
    if (visited[u] == false)
    {
      DFS(adj, u, visited, v);
    }
  }
}
int main()
{
  int v = 4;
  bool visited[v + 1];
  for (int i = 0; i <= v; i++)
    visited[i] = false;
  vector<int> adj[v];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  DFS(adj, 0, visited, v);
  return 0;
}