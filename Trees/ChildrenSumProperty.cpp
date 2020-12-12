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
bool childSum(Node *root)
{
  if (root == NULL)
    return true;
  if (root->right == NULL && root->left == NULL)
    return true;
  else
  {
    int sum = 0;
    if (root->left != NULL)
      sum += root->left->key;
    if (root->right != NULL)
      sum += root->right->key;
    return ((root->key == sum) && childSum(root->left) && childSum(root->right));
  }
}
int main()
{
  Node *root = new Node(20);
  root->left = new Node(8);
  root->right = new Node(12);
  cout << childSum(root) << endl;
}