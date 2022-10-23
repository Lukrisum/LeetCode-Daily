/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int getMinLen(vector<string> &strs)
  {
    int min = 200;
    for (int i = 0; i < strs.size(); i++)
    {
      if (strs[i].length() < min)
      {
        min = strs[i].length();
      }
    }
    return min;
  }

  bool isValidated(vector<string> &strs, int index)
  {
    char target = strs[0][index];
    for (int i = 1; i < strs.size(); i++)
    {
      /* code */
      if (strs[i][index] != target)
      {
        return false;
      }
    }
    return true;
  }

  string longestCommonPrefix(vector<string> &strs)
  {
    if (strs.size() == 1)
    {
      return strs[0];
    }
    int minLen = getMinLen(strs);
    if (minLen == 0)
    {
      return "";
    }
    string res = "";
    string anyStr = strs[0];
    for (int i = 0; i < minLen; i++)
    {
      if (!isValidated(strs, i))
      {
        return res;
      }
      res += anyStr[i];
    }
    return res;
  }
};

// @lc code=end
