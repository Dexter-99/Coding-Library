#include <iostream>
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
int maxLevel = 0;
void leftView(Node *root, int level)
{
  if (root == NULL)
    return;

  if (maxLevel < level)
  {
    cout << root->key << endl ;
    maxLevel = level;
  }
  leftView(root->left, level + 1);
  leftView(root->right, level + 1);
}
int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(12);
  leftView(root, 1);
}