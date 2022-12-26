/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  string longestPalindrome(string s)
  {
    int len = s.length();
    if (s.length() == 1)
    {
      return s;
    }

    int maxL = 1;
    int theL = 0;
    vector<vector<bool>> dp(len, vector<bool>(len, false));

    for (int i = 0; i < len; i++)
    {
      dp[i][i] = true;
    }

    for (int L = 2; L <= len; L++)
    {
      for (int l = 0; l < len; l++)
      {
        int r = l + L - 1;

        if (r >= len)
        {
          break;
        }

        if (s[l] != s[r])
        {
          dp[l][r] = false;
        }
        else if (r - l + 1<= 2)
        {
          dp[l][r] = true;
        }
        else
        {
          dp[l][r] = dp[l + 1][r - 1];
        }

        if (dp[l][r] && L > maxL)
        {
          maxL = L;
          theL = l;
        }
      }
    }

    return s.substr(theL, maxL);
  }
};
// @lc code=end
