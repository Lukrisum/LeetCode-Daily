/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 *
 * [1249] 移除无效的括号
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    stack<int> left;
    stack<int> right;

    for (int i = 0; i < s.length(); i++)
    {
      /* code */
      char c = s[i];
      if (c == ')')
      {
        if (left.empty())
          right.push(i);
        else
          left.pop();
      }
      else if (c == '(')
      {
        left.push(i);
      }
    }

    while (!left.empty())
    {
      int pos = left.top();
      s = s.substr(0, pos) + s.substr(pos + 1);
      left.pop();
    }

    while (!right.empty())
    {
      int pos = right.top();
      s = s.substr(0, pos) + s.substr(pos + 1);
      right.pop();
    }

    return s;
  }
};
// @lc code=end
