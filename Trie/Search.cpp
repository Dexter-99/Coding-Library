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