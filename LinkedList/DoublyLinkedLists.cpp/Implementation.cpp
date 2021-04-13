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
int main()
{
  Node *head = new Node(10);
  Node *temp1 = new Node(20);

  Node *temp2 = new Node(30);
  head->next = temp1;
  temp1->prev = head;
  temp1->next = temp2;
  temp2->prev = temp1;
  return 0;
}