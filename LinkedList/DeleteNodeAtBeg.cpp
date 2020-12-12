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
Node *deleteBeg(Node *head)
{
  if (head == NULL)
  {
    cout << "Empty List" << endl;
  }
  Node *temp = head;
  head = head->next;
  temp->next = NULL;
  delete (temp);
  return head;
}
int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  traverse(head);
  head = deleteBeg(head);
  traverse(head);
  return 0;
}