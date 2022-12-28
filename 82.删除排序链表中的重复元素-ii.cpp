/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *pre = dummy;
    ListNode *cur = head;

    while (cur != nullptr)
    {
      /* code */
      while (cur->next && cur->next->val == cur->val)
      {
        /* code */
        cur = cur->next;
      }

      if (pre->next != cur)
      {
        pre->next = cur->next;
      }
      else
      {
        pre = pre->next;
      }
      cur = cur->next;
    }

    return dummy->next;
  }
};

// @lc code=end
