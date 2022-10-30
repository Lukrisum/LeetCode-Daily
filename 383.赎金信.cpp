/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    unordered_map<char, int> ransomNoteMap;

    for (auto &&c : ransomNote)
    {
      ransomNoteMap[c]++;
    }

    for (auto &&c : magazine)
    {
      ransomNoteMap[c]--;
    }

    for (auto &&c : ransomNote)
    {
      if (ransomNoteMap[c] > 0)
      {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
