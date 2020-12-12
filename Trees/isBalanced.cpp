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
int height(Node *root)
{
  if (root == NULL)
    return 0;
  else
  {
    return max(height(root->left), height(root->right)) + 1;
  }
}
bool isBalanced(Node *root)
{
  if (root == NULL)
    return true;
  int lh = height(root->left);
  int rh = height(root->right);
  return ((abs(lh - rh) <= 1) && isBalanced(root->left) && isBalanced(root->right));
}
int isBalancedEfficient(Node *root)
{
  if (root == NULL)
    return 0;
  int lh = isBalancedEfficient(root->left);
  if (lh == -1)
    return -1;
  int rh = isBalancedEfficient(root->right);
  if (rh == -1)
    return -1;
  if (abs(lh - rh) > 1)
    return -1;
  return max(lh, rh) + 1;
}
int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(12);
  root->right->right = new Node(18);
  root->right->right->right = new Node(25);
  cout << isBalanced(root) << endl;
  cout << isBalancedEfficient(root) << endl;
  ;
}