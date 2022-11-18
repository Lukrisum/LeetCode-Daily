/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    // 微调一下：少一次循环

    if (s.length() != t.length())
    {
      return false;
    }

    int some[26] = {0};

    for (auto &&c : s)
    {
      some[c - 'a']++;
      if (some[c - 'a'] < 0)
      {
        return false;
      }
    }

    return true;
  }
};

// int main()
// {
//   (new Solution)->isAnagram("anagram", "nagaram");
//   return 0;
// }
// @lc code=end
