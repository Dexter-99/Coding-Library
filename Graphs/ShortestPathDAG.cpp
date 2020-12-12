#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
void addEdge(vector<pair<int, int>> list[], int u, int v, int w)
{
  list[u].push_back(make_pair(v, w));
}
vector<int> topologicalSorting(vector<pair<int, int>> adj[], int indegree[], int v)
{
  queue<int> q;
  for (int i = 0; i < v; i++)
    if (indegree[i] == 0)
      q.push(i);
  vector<int> list;
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    list.push_back(curr);
    for (pair<int, int> u : adj[curr])
    {
      indegree[u.first]--;
      if (indegree[u.first] == 0)
        q.push(u.first);
    }
  }
  return list;
}
int main()
{
  int v = 3;
  vector<pair<int, int>> adj[v];
  addEdge(adj, 0, 1, 6);
  addEdge(adj, 0, 2, 2);
  addEdge(adj, 2, 1, 3);
  addEdge(adj, 0, 2, 4);


  int indegree[v] = {0};
  for (int i = 0; i < v; i++)
  {
    for (pair<int, int> u : adj[i])
    {
      indegree[u.first]++;
    }
  }
  vector<int> list = topologicalSorting(adj, indegree, v);
  int distance[v];
  for (int i = 0; i < v; i++)
  {
    distance[i] = INT32_MAX;
  }
  distance[0] = 0;
  for (auto &u : list)
  {
    //   cout<<u<<" ";
    for (pair<int, int> v : adj[u])
    {
      // cout<<v.first<<" "<<v.second<<endl;
      if (distance[v.first] > (distance[u] + v.second))
      {
        distance[v.first] = distance[u] + v.second;
      }
    }
  }
  for (int i = 0; i < v; i++)
    cout << distance[i] << " ";
}