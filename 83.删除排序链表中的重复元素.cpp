/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *optionHead = head;
    while (optionHead != nullptr)
    {
      /* code */
      if (optionHead->next == nullptr)
      {
        break;
      }
      else if (optionHead->next->val == optionHead->val)
      {
        optionHead->next = optionHead->next->next;
      }
      else
      {
        optionHead = optionHead->next;
      }
    }

    return head;
  }
};

// @lc code=end
