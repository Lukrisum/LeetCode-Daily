/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MinStack
{
private:
  int **myArray = nullptr;
  int capacity = 10;
  int myLast = -1;

  int min = 0;
  bool minTouched = false;

public:
  MinStack()
  {
    myArray = (int **)malloc(capacity * sizeof(int *));
    ;
  }

  void push(int val)
  {
    if (myLast + 2 > capacity)
    {
      capacity *= 2;
      myArray = (int **)realloc(myArray, capacity * sizeof(int *));
    }

    if (!minTouched)
    {
      min = val;
      minTouched = true;
    }
    else
    {
      min = min > val ? val : min;
    }

    int vvv = val;
    int *temp = new int[1]{val};
    myLast++;
    myArray[myLast] = temp;
  }

  void pop()
  {
    if (min == top())
    {
      minTouched = false;
      for (int i = 0; i <= myLast - 1; i++)
      {
        if (!minTouched)
        {
          min = *myArray[i];
          minTouched = true;
        }
        else
        {
          min = min > *myArray[i] ? *myArray[i] : min;
        }
      }
    }
    myLast--;
  }

  int top()
  {
    return *myArray[myLast];
  }

  int getMin()
  {
    return min;
  }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
