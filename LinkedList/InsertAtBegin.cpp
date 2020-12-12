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
Node *insertBeg(Node *head, int val)
{
  Node *newNode = new Node(val);
  newNode->next = head;
  head = newNode;
  return head;
}
int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  traverse(head);
  head = insertBeg(head, 5);
  traverse(head);
  return 0;
}