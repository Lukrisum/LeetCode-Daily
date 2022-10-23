/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include <algorithm>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
  int getInt(char c)
  {
    unordered_map<char, int> romanInt;
    romanInt['I'] = 1;
    romanInt['V'] = 5;
    romanInt['X'] = 10;
    romanInt['L'] = 50;
    romanInt['C'] = 100;
    romanInt['D'] = 500;
    romanInt['M'] = 1000;

    return romanInt[c];
  }

  int romanToInt(string s)
  {
    int sum = getInt(s[s.length() - 1]);

    for (int i = s.length() - 1; i >= 1; i--)
    {
      int lastInt = getInt(s[i]);
      int nowInt = getInt(s[i - 1]);
      if (nowInt < lastInt)
      {
        sum -= nowInt;
      }
      else if (nowInt >= lastInt)
      {
        sum += nowInt;
      }
    }

    return sum;
  }
};

// @lc code=end