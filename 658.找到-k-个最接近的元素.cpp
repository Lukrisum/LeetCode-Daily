/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  vector<int> outPut(int left, int right, vector<int> arr)
  {
    vector<int> res;
    for (int i = left; i <= right; i++)
    {
      res.push_back(arr[i]);
    }
    return res;
  }

  vector<int> findClosestElements(vector<int> &arr, int k, int x)
  {
    int left = 0;
    int right = k - 1;

    vector<int> res;

    while (right < arr.size() && arr[right] < x)
    {
      right++;
    }

    while(right >= 1 && abs(arr[right] - x) > abs(arr[right-1] - x)){
      right--;
    }

    left = right + 1 - k;

    return outPut(left, right, arr);
  }
};

// @lc code=end
