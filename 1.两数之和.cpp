/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <stdlib.h>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    auto v = new vector<int>;
    for (size_t i = 0; i < nums.size(); i++)
    {
      int temp = target - nums[i];
      for (size_t j = i + 1; j < nums.size(); j++)
      {
        if (temp == nums[j])
        {
          v->push_back(i);
          v->push_back(j);
          return *v;
        }
      }
    }
    return *v;
  }
};
// @lc code=end
