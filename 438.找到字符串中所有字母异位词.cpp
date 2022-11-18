/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  bool isAnagram(string s, string t)
  {

    int some[26] = {0};

    for (auto &&c : s)
    {
      some[c - 'a']++;
    }

    for (auto &&c : t)
    {
      some[c - 'a']--;
      if (some[c - 'a'] < 0)
      {
        return false;
      }
    }

    return true;
  }

  vector<int> findAnagrams(string s, string p)
  {
    vector<int> res;
    if (s.length() < p.length())
    {
      return res;
    }
    int subLen = p.length();
    for (int i = 0; i < s.length() - subLen + 1; i++)
    {
      string sub = s.substr(i, subLen);
      if (isAnagram(sub, p))
      {
        res.push_back(i);
      }
    }
    return res;
  }
};

// @lc code=end
