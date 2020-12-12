#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<int> adj[], int s, bool visited[])
{
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    // cout << u << " ";
    for (int v : adj[u])
    {
      if (visited[v] == false)
      {
        q.push(v);
        visited[v] = true;
      }
    }
  }
}
void bfsDis(vector<int> adj[], int v)
{
  bool visited[v + 1];
  int count = 0;
  for (int i = 0; i < v; i++)
  {
    if (visited[i] == false)
    {
      bfs(adj, i, visited);
      count++;
    }
  }
  cout << count << endl;
}
int main()
{
  vector<int> adj[7];
  adj[1].push_back(0);
  adj[1].push_back(3);
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);
  adj[3].push_back(2);
  adj[3].push_back(1);
  adj[4].push_back(5);
  adj[4].push_back(6);
  adj[5].push_back(4);
  adj[5].push_back(6);
  adj[6].push_back(4);
  adj[6].push_back(5);
  bfsDis(adj, 6);
  return 0;
}