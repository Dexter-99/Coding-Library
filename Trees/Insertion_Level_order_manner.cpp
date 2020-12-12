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

// Insert A node in an empty position which comes first in level order manner
void insert(int key, Node *root)
{
  Node *newnode = new Node(key);
  if (root == NULL)
  {
    root = newnode;
    return;
  }
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();
    if (curr->left == NULL)
    {
      curr->left = newnode;
      return;
    }
    else
    {
      q.push(curr->left);
    }
    if (curr->right == NULL)
    {
      curr->right = newnode;
      return;
    }
    else
    {
      q.push(curr->right);
    }
  }
}
void levelOrderPrint(Node *root)
{
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();
    cout << curr->key << endl;
    if (curr->left != NULL)
    {

      q.push(curr->left);
    }
    if (curr->right != NULL)
    {

      q.push(curr->right);
    }
  }
}
int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->left->right = new Node(18);
  root->right = new Node(12);

  insert(20, root);
  levelOrderPrint(root);
}