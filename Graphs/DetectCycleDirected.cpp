#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> list[], int u, int v)
{
  list[u].push_back(v);
}
bool DFS(vector<int> adj[], int s, bool visited[], bool rect[])
{
  visited[s] = true;
  rect[s] = true;
  for (int u : adj[s])
  {
    if (visited[u] == false && (DFS(adj, u, visited, rect) == true))
      return true;
    else if (rect[u] == true)
      return true;
  }
  rect[s] = false;
  return false;
}
int main()
{
  int v = 6;
  bool visited[v];
  bool rect[v];
  for (int i = 0; i < v; i++)
    visited[i] = false;
  for (int i = 0; i < v; i++)
    rect[i] = false;
  vector<int> adj[v];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 5);
  addEdge(adj, 5, 2);
  addEdge(adj, 5, 3);
  bool f = false;
  for (int i = 0; i < v; i++)
  {
    if (visited[i] == false && (DFS(adj, i, visited, rect) == true))
      f = true;
  }
  cout << f << endl;
  return 0;
}