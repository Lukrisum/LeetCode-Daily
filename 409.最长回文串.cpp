/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int longestPalindrome(string s)
  {
    vector<int> count(128);
    for (auto &&c : s)
    {
      count[c]++;
    }

    int ans = 0;
    for (auto &&i : count)
    {
      ans += i / 2 * 2;
      if (i % 2 == 1 && ans % 2 == 0)
      {
        ans++;
      }
    }
    return ans;
  }
};

// @lc code=end
