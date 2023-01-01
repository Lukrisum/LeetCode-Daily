/*
 * @lc app=leetcode.cn id=2507 lang=cpp
 *
 * [2507] 使用质因数之和替换后可以取到的最小值
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  int helper(int n)
  {
    // 枚举，分解质因数
    int sum = 0;
    int origin = n;

    while (n % 2 == 0)
    {
      sum += 2;
      n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
      while (n % i == 0)
      {
        sum += i;
        n /= i;
      }
    }

    if (n > 2)
    {
      sum += n;
    }

    if (sum == origin)
    {
      return sum;
    }

    return smallestValue(sum);
  }

  int smallestValue(int n)
  {
    return helper(n);
  }
};

// @lc code=end
