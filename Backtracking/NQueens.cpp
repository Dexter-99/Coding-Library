#include <iostream>
using namespace std;
bool board[100][100];
bool isSafe(int n, int row, int col)
{
  for (int i = 0; i < col; i++)
  {
    if (board[row][i] == 1)
      return false;
  }
  for (int i = row, j = col; j >= 0 && i >= 0; i--, j--)
  {
    if (board[i][j] == 1)
      return false;
  }
  for (int i = row, j = col; j >= 0 && i < n; i++, j--)
  {
    if (board[i][j] == 1)
      return false;
  }
  return true;
}
bool nqueen(int n, int col)
{
  if (n == col)
    return true;
  for (int i = 0; i < n; i++)
  {
    if (isSafe(n, i, col))
    {
      board[i][col] = 1;
      if (nqueen(n, col + 1))
      {
        return true;
      }
      board[i][col] = 0;
    }
  }
  return false;
}
int main()
{
  int n = 4;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      board[i][j] = false;
    }
  }
  if (nqueen(n, 0))
  {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}