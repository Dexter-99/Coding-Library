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
  if (head == NULL)
    return;

  cout << head->data << " ";
  Node *curr = head->next;
  while (curr != head)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}
Node *insert(Node *head, int key)
{
  Node *newNode = new Node(key);
  if (head == NULL)
  {
    newNode->next = newNode;
    return newNode;
  }
  Node *curr = head;
  while (curr->next != head)
  {
    curr = curr->next;
  }
  newNode->next = head;
  head = newNode;
  curr->next = head;
  return head;
}
int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  // Last Node pointing to the first Node
  head->next->next->next = head;

  traverse(head);
  head = insert(head, 5);
  traverse(head);
  return 0;
}