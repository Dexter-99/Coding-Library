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
int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(12);
}