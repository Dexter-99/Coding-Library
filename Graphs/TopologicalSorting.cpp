#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
void addEdge(vector<int> list[], int u, int v)
{
  list[u].push_back(v);
}
void topologicalSorting(vector<int> adj[], int indegree[], int v)
{
  queue<int> q;
  for (int i = 0; i < v; i++)
    if (indegree[i] == 0)
      q.push(i);
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    cout << curr << " ";
    for (int u : adj[curr])
    {
      indegree[u]--;
      if (indegree[u] == 0)
        q.push(u);
    }
  }
}
void topologicalSortingDfs(vector<int> adj[], bool visited[], int s, stack<int> &st)
{
  visited[s] = true;
  for (int u : adj[s])
  {
    if (visited[u] == false)
    {
      topologicalSortingDfs(adj, visited, u, st);
    }
  }
  st.push(s);
}
int main()
{
  int v = 5;
  vector<int> adj[v];
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 2, 3);
  addEdge(adj, 1, 3);
  addEdge(adj, 1, 4);
  int indegree[v] = {0};
  for (int i = 0; i < v; i++)
  {
    for (int u : adj[i])
    {
      indegree[u]++;
    }
  }
  topologicalSorting(adj, indegree, v);
  bool visited[v];
  for (int i = 0; i < v; i++)
  {
    visited[i] == false;
  }
  stack<int> st;
  for (int i = 0; i < v; i++)
  {
    if (visited[i] == false)
    {
      topologicalSortingDfs(adj, visited, i, st);
    }
  }
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
}