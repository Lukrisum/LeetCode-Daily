/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
  {
    sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] > b[1]; });
    int sum = 0;

    for (auto &&boxType : boxTypes)
    {

      int numberOfBoxes = boxType[0];
      int numberOfUnitsPerBox = boxType[1];
      if (truckSize > numberOfBoxes)
      {
        sum += numberOfUnitsPerBox * numberOfBoxes;
        truckSize -= numberOfBoxes;
      }
      else
      {
        sum += numberOfUnitsPerBox * truckSize;
        break;
      }
    }

    return sum;
  }
};

// @lc code=end
