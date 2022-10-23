/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0)
    {
      return false;
    }
    string xStr = to_string(x);
    for (int i = 0; i < xStr.length(); i++)
    {
      /* code */
      if (xStr[i] != xStr[xStr.length() - 1 - i])
      {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
