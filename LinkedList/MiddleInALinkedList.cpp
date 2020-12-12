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
Node *middle(Node *head)
{
  if (head == NULL)
    return NULL;
  Node *curr1 = head;
  Node *curr2 = head;
  while (curr2 != NULL && curr2->next != NULL)
  {
    curr1 = curr1->next;
    curr2 = curr2->next->next;
  }
  return curr1;
}
int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);
  cout << middle(head)->data << endl;
  return 0;
}