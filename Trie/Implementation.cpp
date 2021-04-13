#include <iostream>
using namespace std;
struct TrieNode
{
  TrieNode *child[26];
  bool isEnd;
  TrieNode()
  {
    isEnd = false;
    for (int i = 0; i < 26; i++)
    {
      child[i] = NULL;
    }
  }
};
void insert(TrieNode *root, string s)
{
  TrieNode *curr = root;
  for (int i = 0; i < s.length(); i++)
  {
    int idx = s[i] - 'a';
    if (curr->child[idx] == NULL)
    {
      TrieNode *newNode = new TrieNode();
      curr->child[idx] = newNode;
    }
    curr = curr->child[idx];
  }
  curr->isEnd = true;
  // return root;
}
void display_Trie(TrieNode *root, string res)
{
  if (root->isEnd)
  {
    cout << res << endl;
  }

  for (int i = 0; i < 26; i++)
  {
    if (root->child[i])
    {
      res = res + (char)('a' + i);
      display_Trie(root->child[i], res);
      res.erase(res.begin() + res.length() - 1);
    }
  }
}
bool search(TrieNode *root, string key)
{
  TrieNode *curr = root;
  for (int i = 0; i < key.length(); i++)
  {
    int idx = key[i] - 'a';
    if (curr->child[idx] == NULL)
      return false;
    curr = curr->child[idx];
  }
  return curr->isEnd;
}
bool isEmpty(TrieNode *root)
{
  for (int i = 0; i < 26; i++)
  {
    if (root->child[i] != NULL)
      return false;
  }
  return true;
}
TrieNode *deleteWord(TrieNode *root, string key, int i)
{
  if (root == NULL)
    return root;
  if (i == key.length())
  {
    root->isEnd = false;
    if (isEmpty(root))
    {
      delete (root);
      return NULL;
    }
  }
  int idx = key[i] - 'a';
  root->child[idx] = deleteWord(root->child[idx], key, i + 1);
  if (isEmpty(root) && root->isEnd == false)
  {
    delete (root);
    return NULL;
  }
  return root;
}
int main()
{
  int n = 6;
  string keys[6] = {"bad", "bat", "geeks", "geeks", "cat", "cut"};
  TrieNode *root = new TrieNode();
  for (int i = 0; i < 6; i++)
  {
    insert(root, keys[i]);
  }
  display_Trie(root, "");
  // root = deleteWord(root, "cat", 0);
  display_Trie(root, "");
  cout << (search(root, "cat") ? "YES" : "NO") << endl;
  return 0;
}