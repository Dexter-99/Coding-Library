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