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