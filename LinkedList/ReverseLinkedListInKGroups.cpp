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

Node *reverseKGroups(Node *head, int k)
{
  Node *curr = head;
  Node *prev = NULL;
  int count = 0;
  while (curr != NULL && count < k)
  {
    Node *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
    count++;
  }
  if (curr != NULL)
  {
    Node *list_head = reverseKGroups(curr, k);
    head->next = list_head;
  }
  return prev;
}

// Iterative Approach

Node *reverseKGroups2(Node *head, int k)
{
  Node *curr = head;
  Node *prevFirst = NULL;
  bool isFirstPass = true;
  while (curr != NULL)
  {
    Node *first = curr;
    int count = 0;
    Node *prev = NULL;
    while (curr != NULL && count < k)
    {
      Node *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
      count++;
    }
    if (isFirstPass)
    {
      head = prev;
      isFirstPass = false;
    }
    else
    {
      prevFirst->next = prev;
    }
    prevFirst = first;
  }
  return head;
}

int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);
  traverse(head);
  Node *curr = head;
  int k = 2;
  head = reverseKGroups(head, k);
  traverse(head);
  head = reverseKGroups2(head, k);
  traverse(head);
  return 0;
}