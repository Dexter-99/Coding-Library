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
void deleteDeepest(Node *root, Node *temp)
{
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();
    if (curr == temp)
    {
      curr = NULL;
      delete (temp);
      return;
    }
    if (curr->left)
    {
      if (curr->left == temp)
      {
        curr->left = NULL;
        delete (temp);
        return;
      }
      else
      {
        q.push(curr->left);
      }
    }
    if (curr->right)
    {
      if (curr->right == temp)
      {
        curr->right = NULL;
        delete (temp);
        return;
      }
      else
      {
        q.push(curr->right);
      }
    }
  }
}
// Delete A node if present in a binary tree and replace it with the deepest rightmost node
Node *deleteNode(int key, Node *root)
{
  if (root == NULL)
    return root;

  // Single Node Tree
  if (root->left == NULL && root->right == NULL)
  {
    if (root->key == key)
      return NULL;
    else
    {
      return root;
    }
  }
  queue<Node *> q;
  q.push(root);
  Node *curr;
  // Node to be deleted
  Node *temp = NULL;
  while (!q.empty())
  {
    curr = q.front();
    q.pop();
    if (curr->key == key)
    {
      temp = curr;
    }
    if (curr->left)
    {
      q.push(curr->left);
    }
    if (curr->right)
    {
      q.push(curr->right);
    }
  }
  if (temp != NULL)
  {
    // Curr->will point to last node in level order
    int val = curr->key;

    deleteDeepest(root, curr);
    temp->key = val;
  }
  return root;
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

  levelOrderPrint(root);
  cout << endl;
  root = deleteNode(15, root);
  levelOrderPrint(root);
}