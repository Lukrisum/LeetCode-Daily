/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  bool backspaceCompare(string s, string t)
  {

    stack<char> aSt, bSt;
    for (auto &&i : s)
    {
      if (i == '#')
      {
        if (!aSt.empty())
          aSt.pop();
      }
      else
      {
        aSt.push(i);
      }
    }

    for (auto &&i : t)
    {
      if (i == '#')
      {
        if (!bSt.empty())
          bSt.pop();
      }
      else
      {
        bSt.push(i);
      }
    }

    if (aSt.size() != bSt.size())
    {
      return false;
    }

    while (!aSt.empty())
    {
      if (aSt.top() != bSt.top())
      {
        return false;
      }
      aSt.pop();
      bSt.pop();
    }

    return true;
  }
};

// @lc code=end
