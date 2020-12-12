#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> list[], int u, int v)
{
  list[u].push_back(v);
  list[v].push_back(u);
}
void printList(vector<int> adj[], int v)
{
  for (int i = 0; i < v; i++)
  {
    cout << i << " ";
    for (int j = 0; j < adj[i].size(); j++)
    {
      cout << adj[i][j] << " ";
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
  addEdge(adj, 1, 3);
}