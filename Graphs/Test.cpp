#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
}
void bfs(vector<int> adj[], int s, bool visited[], int distance[], int parent[])
{
  queue<int> q;
  q.push(s);
  visited[s] = true;
  distance[s] = 0;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (int v : adj[u])
    {
      if (visited[v] == false)
      {
        distance[v] = distance[u] + 1;
        parent[v] = u;
        visited[v] = true;
        q.push(v);
      }
    }
  }
}
void dfs(vector<int> adj[], int s, bool visited[])
{
  visited[s] = true;
  cout << s << " ";
  for (int u : adj[s])
  {
    if (visited[u] == false)
    {
      dfs(adj, u, visited);
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
  addEdge(adj, 2, 3);

  bool visited[v];
  int distance[v];
  int parent[v];
  for (int i = 0; i < v; i++)
    visited[i] = false;
  for (int i = 0; i < v; i++)
    distance[i] = -1;
  for (int i = 0; i < v; i++)
    parent[i] = -1;

  bfs(adj, 0, visited, distance, parent);
  cout << endl;
  for (int i = 0; i < v; i++)
    cout << distance[i] << " ";
  cout << endl;

  // Print path from source to a vertex v if it exists
  int val = 3;
  if (!visited[val])
    cout << "No Path" << endl;
  else
  {
    vector<int> path;
    int src = val;
    while (src != -1)
    {
      path.push_back(src);
      src = parent[src];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
      cout << x << "->";
  }

  for (int i = 0; i < v; i++)
    visited[i] = false;
  // for (int i = 0; i < v; i++)
  // if (visited[i] == false)
  dfs(adj, 0, visited);

  return 0;
}