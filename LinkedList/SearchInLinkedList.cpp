#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};
void traverse(Node *head)
{
  Node *curr = head;
  while (curr != NULL)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
}

int searchRecursive(Node *head, int val)
{
  if (head == NULL)
    return -1;
  if (head->data == val)
    return 1;
  else
  {
    int res = searchRecursive(head->next, val);
    return (res == -1) ? -1 : res + 1;
  }
}
int searchIterative(Node *head, int val)
{
  int pos = 1;
  Node *curr = head;
  while (curr != NULL)
  {
    if (curr->data == val)
      return pos;
    curr = curr->next;
    pos++;
  }
  return -1;
}
int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  cout << searchRecursive(head, 15) << endl;
  cout << searchIterative(head, 15) << endl;
  return 0;
}