/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
// struct ListNode
// {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };
class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return nullptr;
    }

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != nullptr && slow != nullptr)
    {
      if (fast->next != nullptr)
      {
        fast = fast->next->next;
      }
      else
      {
        break;
      }

      slow = slow->next;

      if (fast == slow)
      {
        ListNode *ptr = head;
        while (ptr != slow)
        {
          ptr = ptr->next;
          slow = slow->next;
        }
        return ptr;
      }
    }

    return nullptr;
  }
};
// @lc code=end
