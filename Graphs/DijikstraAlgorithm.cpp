#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
void addEdge(vector<pii> adj[], int u, int v, int w)
{
  adj[u].push_back({v, w});
  adj[v].push_back({u, w});
}
void dijikstra(vector<pii> adj[], int distance[], bool visited[])
{
  priority_queue<pii, vector<pii>, greater<pii>> q;
  distance[1] = 0;
  q.push({0, 1});
  while (!q.empty())
  {
    int curr = q.top().second;
    q.pop();
    if (visited[curr] == true)
      continue;
    visited[curr] = true;
    for (pii x : adj[curr])
    {
      int v = x.first;
      int w = x.second;

      if (distance[v] > (distance[curr] + w))
      {
        distance[v] = distance[curr] + w;
        q.push({distance[v], v});
      }
    }
  }
}
int main()
{
  int v = 5;
  vector<pii> adj[v + 1];
  addEdge(adj, 1, 2, 5);
  addEdge(adj, 1, 4, 9);
  addEdge(adj, 1, 5, 1);
  addEdge(adj, 2, 3, 2);
  addEdge(adj, 4, 3, 6);
  addEdge(adj, 5, 4, 2);
  int distance[v + 1];
  bool visited[v + 1];
  for (int i = 0; i <= v; i++)
    distance[i] = INT32_MAX;
  for (int i = 0; i <= v; i++)
    visited[i] = false;
  dijikstra(adj, distance, visited);
  for (int i = 1; i <= v; i++)
    cout << distance[i] << " ";
  cout << endl;
  return 0;
}
