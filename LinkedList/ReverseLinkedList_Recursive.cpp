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

// Recursive Approach
Node *reverse(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  Node *rest_head = reverse(head->next);
  Node *rest_tail = head->next;
  rest_tail->next = head;
  head->next = NULL;
  return rest_head;
}
// Another Approach
Node *reverse2(Node *curr, Node *prev)
{
  if (curr == NULL)
    return prev;

  Node *next = curr->next;
  curr->next = prev;
  prev = curr;
  return reverse2(next, prev);
}
int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);
  traverse(head);
  head = reverse(head);
  traverse(head);
  head = reverse2(head, NULL);
  traverse(head);
  return 0;
}