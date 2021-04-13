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
// Fast And Slow Pointer Concept
// Single Traversal
Node *nthNodeFromLast(Node *head, int n)
{
  if (head == NULL)
    return NULL;
  Node *curr1 = head;
  Node *curr2 = head;
  for (int i = 0; i < n; i++)
  {
    if (curr2 == NULL)
      return NULL;
    curr2 = curr2->next;
  }
  while (curr2 != NULL)
  {
    curr1 = curr1->next;
    curr2 = curr2->next;
  }
  return curr1;
}
int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);
  cout << nthNodeFromLast(head, 1)->data << endl;
  return 0;
}