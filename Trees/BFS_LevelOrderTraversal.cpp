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
void bfs(Node *root)
{

  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();
    cout << (curr->key) << endl;
    if (curr->left != NULL)
      q.push(curr->left);
    if (curr->right != NULL)
      q.push(curr->right);
  }
}
int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(12);
  root->right->right = new Node(18);
  root->left->right = new Node(25);
  bfs(root);
}