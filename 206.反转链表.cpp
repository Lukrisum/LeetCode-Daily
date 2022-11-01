/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
  ListNode *reverseList(ListNode *head)
  {
    // stack<int> tempNums;

    // while (head != nullptr)
    // {
    //   /* code */
    //   tempNums.push(head->val);
    //   head = head->next;
    // }

    // ListNode *resHead = new ListNode(-1);
    // ListNode *optionHead = resHead;
    // while (tempNums.size() > 0)
    // {
    //   /* code */
    //   int temp = tempNums.top();
    //   tempNums.pop();

    //   optionHead->next = new ListNode(temp);
    //   optionHead = optionHead->next;
    // }

    // return resHead->next;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr)
    {
      /* code */
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

// @lc code=end
