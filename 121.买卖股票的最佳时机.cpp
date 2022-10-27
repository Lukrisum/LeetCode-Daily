/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    // dp 😋
    int earn[100000];
    int maxEarn = -10001;
    earn[prices.size() - 1] = 0;
    for (int i = prices.size() - 1; i >= 0; i--)
    {
      /* code */
      if (i < prices.size() - 1)
      {
        earn[i] = max(prices[i + 1] + earn[i + 1] - prices[i], prices[i + 1] - prices[i]);
        // printf("%d\n", earn[i]);
      }
      if (earn[i] > maxEarn)
      {
        maxEarn = earn[i];
      }
    }
    return maxEarn;
  }
};

// int main()
// {
//   vector<int> a = {7, 1, 5, 3, 6, 4};
//   (new Solution)->maxProfit(a);
//   return 0;
// }
// @lc code=end
