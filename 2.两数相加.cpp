/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

// struct ListNode
// {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *h1 = l1;
    ListNode *h2 = l2;

    ListNode *res = new ListNode(0, nullptr);
    ListNode *tempH = res;

    int added = 0;

    while (h1 != nullptr || h2 != nullptr || added != 0)
    {
      int num1 = 0;
      int num2 = 0;

      if (h1 != nullptr)
      {
        num1 = h1->val;
        h1 = h1->next;
      }

      if (h2 != nullptr)
      {
        num2 = h2->val;
        h2 = h2->next;
      }

      int temp = num1 + num2 + added;
      added = temp / 10;
      // cout<<num1<<" "<<num2<<":"<<temp<<endl;
      // cout<<num1<<" "<<num2<<":"<<temp<<endl;

      tempH->val = temp%10;
      if (h1 != nullptr || h2 != nullptr || added != 0)
      {
        ListNode *next = new ListNode(0, nullptr);
        tempH->next = next;
        tempH = tempH->next;
        cout<<tempH->val;
      }
    }

    return res;
  }
};
// @lc code=end
