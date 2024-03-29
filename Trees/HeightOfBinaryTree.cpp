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
int height(Node *root)
{
  if (root == NULL)
    return 0;
  else
  {
    return max(height(root->left), height(root->right)) + 1;
  }
}
int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(12);
  root->right->right = new Node(18);
  root->left->right = new Node(25);
  cout << height(root) << endl;
  ;
}