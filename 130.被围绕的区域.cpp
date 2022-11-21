/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  void bfs(vector<vector<char>> &board, int i, int j)
  {
    int m = board[0].size();
    int n = board.size();

    queue<vector<int>> q;
    q.push({i, j});
    board[i][j] = 'A';

    while (!q.empty())
    {
      vector<int> pos = q.front();
      q.pop();
      int ii = pos[0];
      int jj = pos[1];

      if (ii + 1 < n && board[ii + 1][jj] == 'O')
      {
        board[ii + 1][jj] = 'A';
        q.push({ii + 1, jj});
      }

      if (jj + 1 < m && board[ii][jj + 1] == 'O')
      {
        board[ii][jj + 1] = 'A';
        q.push({ii, jj + 1});
      }

      if (ii - 1 >= 0 && board[ii - 1][jj] == 'O')
      {
        board[ii - 1][jj] = 'A';
        q.push({ii - 1, jj});
      }

      if (jj - 1 >= 0 && board[ii][jj - 1] == 'O')
      {
        board[ii][jj - 1] = 'A';
        q.push({ii, jj - 1});
      }
    }
  }

  void solve(vector<vector<char>> &board)
  {
    int m = board[0].size();
    int n = board.size();

    for (int i = 0; i < m; i++)
    {
      if (board[0][i] == 'O')
      {
        bfs(board, 0, i);
      }

      if (board[n - 1][i] == 'O')
      {
        bfs(board, n - 1, i);
      }
    }

    for (int i = 0; i < n; i++)
    {

      if (board[i][0] == 'O')
      {
        bfs(board, i, 0);
      }

      if (board[i][m - 1] == 'O')
      {
        bfs(board, i, m - 1);
      }
    }

    for (int i = 0; i < n; i++)
    {
      /* code */
      for (int j = 0; j < m; j++)
      {
        /* code */
        if (board[i][j] == 'A')
        {
          board[i][j] = 'O';
        }
        else if (board[i][j] == 'O')
        {
          board[i][j] = 'X';
        }
      }
    }
  }
};

// @lc code=end
