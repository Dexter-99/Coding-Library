#include <iostream>
#include <stack>
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
// INORDER
void inorder(Node *root)
{
  stack<Node *> st;
  Node *curr = root;
  while (curr != NULL || !st.empty())
  {
    while (curr != NULL)
    {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    cout << curr->key << endl;
    curr = curr->right;
    /* code */
  }
}
// PREODER
// void preorder(Node *root)
// {
//   if (root != NULL)
//   {
//     cout << (root->key) << " ";
//     preorder(root->left);
//     preorder(root->right);
//   }
// }
// POSTORDER
// void postorder(Node *root)
// {
//   if (root != NULL)
//   {
//     postorder(root->left);
//     postorder(root->right);
//     cout << (root->key) << " ";
//   }
// }

int main()
{
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(12);
  root->right->right = new Node(18);
  root->left->right = new Node(25);
  inorder(root);
  cout << endl;
  // preorder(root);
  // cout << endl;
  // postorder(root);
}