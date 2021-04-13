#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
  TrieNode *child[2];
  TrieNode()
  {
    child[0] = NULL;
    child[1] = NULL;
  }
};
bool distinct(TrieNode *root, int row, int col, vector<vector<int>> &mat)
{
  TrieNode *curr = root;
  bool flag = false;
  for (int i = 0; i < col; i++)
  {
    int idx = mat[row][i];
    if (curr->child[idx] == NULL)
    {
      curr->child[idx] = new TrieNode();
      flag = true;
    }
    curr = curr->child[idx];
  }
  return flag;
}
int main()
{
  int row = 4, col = 3;
  vector<vector<int>> mat = {{1, 1, 0},
                             {1, 1, 0},
                             {1, 1, 0},
                             {1, 1, 0}};
  int res = 0;
  TrieNode *root = new TrieNode();
  for (int i = 0; i < row; i++)
  {
    if (distinct(root, i, col, mat))
      res++;
  }
  cout << res << endl;
  return 0;
}