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
int res = 0;
// O(n) Approach
int diameter(Node *root)
{

  if (root == NULL)
    return 0;
  int l = diameter(root->left);
  int r = diameter(root->right);
  res = max(res, (1 + l + r));
  return 1 + max(l, r);
}
int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(12);
  root->right->right = new Node(18);
  root->left->right = new Node(25);
  diameter(root);
  cout << res << endl;
}