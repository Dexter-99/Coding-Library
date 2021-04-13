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
    cout << curr->data << endl;
    curr = curr->next;
  }
}
Node *merge(Node *head1, Node *head2)
{
  Node *curr1 = head1, *curr2 = head2;
  Node *res = NULL;
  Node *tail = NULL;
  while (curr1 != NULL && curr2 != NULL)
  {
    Node *temp;
    if (curr1->data <= curr2->data)
    {
      temp = curr1;
      curr1 = curr1->next;
    }
    else
    {
      temp = curr2;
      curr2 = curr2->next;
    }
    if (res == NULL)
    {
      res = temp;
    }
    else
    {
      tail->next = temp;
    }
    tail = temp;
  }
  if (curr1 != NULL)
    tail->next = curr1;
  if (curr2 != NULL)
    tail->next = curr2;
  return res;
}
int main()
{
  Node *head1 = new Node(10);
  head1->next = new Node(20);
  head1->next->next = new Node(30);
  Node *head2 = new Node(5);
  head2->next = new Node(15);
  Node *res = merge(head1, head2);
  traverse(res);
  return 0;
}