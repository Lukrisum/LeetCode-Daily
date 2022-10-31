/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode *resList = new ListNode(-1);
    ListNode *head = resList;
    while (list1 != nullptr && list2 != nullptr)
    {
      /* code */
      if (list1->val > list2->val)
      {
        resList->next = list2;
        list2 = list2->next;
      }
      else
      {
        resList->next = list1;
        list1 = list1->next;
      }
      resList = resList->next;
    }

    resList->next = list1 == nullptr ? list2 : list1;

    return head->next;
  }
};
// @lc code=end
