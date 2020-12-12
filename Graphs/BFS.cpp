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
    cout << u << " ";
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
  bool  visited[7];
  for(int i=0;i<7;i++)
  {
    visited[i]=false;
  }
  bfs(adj,0,visited);
  return 0;
}