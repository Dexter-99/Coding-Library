
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
int width(Node *root)
{
  queue<Node *> q;
  q.push(root);
  int width = -1;

  while (!q.empty())
  {
    int len = q.size();
    width = max(width, len);
    for (int i = 0; i < len; i++)
    {
      Node *curr = q.front();
      q.pop();

      if (curr->left != NULL)
        q.push(curr->left);

      if (curr->right != NULL)
        q.push(curr->right);
    }
  }
}

int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(12);
  root->right->right = new Node(18);
  root->left->right = new Node(25);
  width(root);
}