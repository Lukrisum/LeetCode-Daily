/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
  // 1. 递归定义
  ListNode *deleteDuplicates(ListNode *head)
  {

    // 2. 结束条件
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }

    // 3. 递归的等价逻辑
    ListNode *res;
    if (head->val == head->next->val)
    {
      ListNode *move = head->next;
      while (move->next && move->val == move->next->val)
      {
        move = move->next;
      }
      res = deleteDuplicates(move->next);
    }
    else
    {
      res = head;
      res->next = deleteDuplicates(head->next);
    }
    return res;
  }
};

// @lc code=end