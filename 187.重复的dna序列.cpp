/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  vector<string> findRepeatedDnaSequences(string s)
  {
    vector<string> res;
    int len = s.length();
    if (len < 10)
    {
      return res;
    }

    unordered_map<string, int> mp;

    for (int l = 0; l <= len - 10; l++)
    {
      string temp = s.substr(l, 10);
      mp[temp]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
      if (it->second > 1)
      { 
        res.push_back(it->first);
      }
    }

    return res;
  }
};
// @lc code=end
