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
Node *addTwoList(Node *head1, Node *head2)
{
  Node *first = head1, *second = head2, *prev = NULL, *res = NULL, *temp = NULL;
  int carry = 0, sum = 0;
  while (first != NULL || second != NULL)
  {
    int sum = carry + ((first) ? first->data : 0) + ((second) ? second->data : 0);
    carry = sum >= 10 ? 1 : 0;
    sum %= 10;
    temp = new Node(sum);

    if (res == NULL)
    {
      res = temp;
    }
    else
    {
      prev->next = temp;
    }
    prev = temp;
    if (first)
      first = first->next;
    if (second)
      second = second->next;
  }
  if (carry)
    temp->next = new Node(carry);
  return res;
}
int main()
{
  Node *head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);
  head1->next->next->next = new Node(4);
  Node *head2 = new Node(9);
  head2->next = new Node(2);
  head2->next->next = new Node(3);
  head2->next->next->next = new Node(4);

  Node *head = addTwoList(head1, head2);
  traverse(head);
  return 0;
}