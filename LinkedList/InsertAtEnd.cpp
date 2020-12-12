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
Node *insertEnd(Node *head, int val)
{
  Node *newNode = new Node(val);
  if (head == NULL)
    return newNode;
  Node *curr = head;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  curr->next = newNode;
  return head;
}
int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  traverse(head);
  head = insertEnd(head, 5);
  traverse(head);
  return 0;
}