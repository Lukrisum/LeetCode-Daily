/*
 * @lc app=leetcode.cn id=1759 lang=cpp
 *
 * [1759] 统计同构子字符串的数目
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int countHomogenous(string s)
  {
    long long res = 0;
    long long mod = 1e9 + 7;
    int cnt = 0;
    char prev = s[0];

    for (auto &&c : s)
    {
      if (c == prev)
      {
        cnt++;
      }
      else
      {
        res += (long long)(cnt + 1) * cnt / 2;
        cnt = 1;
        prev = c;
      }
    }
    res += (long long)(cnt + 1) * cnt / 2;

    return res % mod;
  }
};

// @lc code=end
