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
Node *deleteEnd(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    cout << "Empty List" << endl;
  }
  Node *curr = head;
  while (curr->next->next != NULL)
  {
    curr = curr->next;
  }
  delete (curr->next);
  curr->next = NULL;
  return head;
}
int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  traverse(head);
  head = deleteEnd(head);
  traverse(head);
  return 0;
}