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
void dfs(Node *root, int k)
{
  if (root == NULL)
    return;
  if (k == 0)
    cout << root->key << endl;
  dfs(root->left, k - 1);
  dfs(root->right, k - 1);
}
// We can also do this using level order traversal 
int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(12);
  root->right->right = new Node(18);
  root->left->right = new Node(25);
  dfs(root, 0);
}