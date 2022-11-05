/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  int findNthDigit(int n)
  {
    
    int digit = 1;
    long start = 1;
    long count = 9;

    while (n > count)
    {
      n -= count;
      start *= 10;
      digit += 1;
      count = start * 9 * digit;
    }

    int num = start + (n - 1) / digit;

    string s = to_string(num);
    return s[(n - 1) % digit] - '0';
  }
};

// @lc code=end
