#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node(int x)
  {
    data = x;
    prev = NULL;
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
  cout << endl;
}
Node *insertBeg(Node *head, int key)
{
  Node *newNode = new Node(key);
  newNode->next = head;
  if (head != NULL)
  {
    head->prev = newNode;
  }
  head = newNode;
}
int main()
{
  Node *head = new Node(10);
  Node *temp1 = new Node(20);

  Node *temp2 = new Node(30);
  head->next = temp1;
  temp1->prev = head;
  temp1->next = temp2;
  temp2->prev = temp1;
  traverse(head);
  head = insertBeg(head, 5);
  traverse(head);
  return 0;
}