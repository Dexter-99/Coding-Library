#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> list[], int u, int v)
{
  list[u].push_back(v);
  list[v].push_back(u);
}
bool DFS(vector<int> adj[], int s, bool visited[], int parent)
{
  visited[s] = true;
  for (int u : adj[s])
  {
    if (visited[u] == false)
    {
      if (DFS(adj, u, visited, s) == true)
        return true;
    }
    else if (u != parent)
    {
      return true;
    }
  }
  return false;
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
  addEdge(adj, 1, 3);
  cout << DFS(adj, 0, visited, -1) << endl;
  return 0;
}