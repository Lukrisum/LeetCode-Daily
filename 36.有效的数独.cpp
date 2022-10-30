/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    bool isValid = true;

    // 行遍历
    for (auto &&row : board)
    {
      unordered_set<char> resMap;
      int size = 0;
      for (auto &&item : row)
      {
        if (item != '.')
        {
          size++;
          resMap.insert(item);
        }
      }
      if (size > resMap.size())
      {
        isValid = false;
      }
    }

    // 列遍历
    for (int col = 0; col < 9; col++)
    {
      unordered_set<char> resMap;
      int size = 0;
      /* code */
      for (int row = 0; row < 9; row++)
      {
        
        /* code */
        if (board[row][col] != '.')
        {
          size++;
          resMap.insert(board[row][col]);
        }
      }
      if (size > resMap.size())
      {
        isValid = false;
      }
    }

    // 9宫格遍历
    for (int i = 0; i < 9; i++)
    {
      /* code */
      int row = 3 * (i / 3);
      int col = (i % 3) * 3;
      unordered_set<char> resMap;
      int size = 0;
      for (int j = 0; j < 9; j++)
      {
        /* code */
        int rowAdd = j / 3;
        int colAdd = j % 3;
        if (board[row + rowAdd][col + colAdd] != '.')
        {
          size++;
          resMap.insert(board[row + rowAdd][col + colAdd]);
        }
      }
      if (size > resMap.size())
      {
        isValid = false;
      }
    }

    return isValid;
  }
};

// @lc code=end
