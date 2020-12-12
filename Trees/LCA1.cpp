#include <iostream>
#include <queue>
using namespace std;
struct Node
{
  int key;
  Node *left;
  Node *right;
  Node(int k)
  {
    key = k;
    left = right = NULL;
  }
};
bool findPath(Node *root, vector<Node *> &path, int n)
{
  if (root == NULL)
    return false;
  path.push_back(root);
  if (root->key == n)
    return true;
  if (findPath(root->left, path, n) || findPath(root->right, path, n))
    return true;
  path.pop_back();
  return false;
}
int lca(int n1, int n2, Node *root)
{
  vector<Node *> path1, path2;
  if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false)
    return -1;
  int res = -1;
  for (int i = 0; i < path1.size() && i < path2.size(); i++)
  {
    if (path1[i] == path2[i])
    {
      res = path1[i]->key;
    }
    else
    {
      break;
    }
  }
  return res;
}

int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(12);
  root->right->right = new Node(18);
  root->left->right = new Node(25);

  cout << lca(25, 18, root) << endl;
}