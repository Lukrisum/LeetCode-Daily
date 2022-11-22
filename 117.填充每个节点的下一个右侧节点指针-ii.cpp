/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
  Node *connect(Node *root)
  {

    if (root == nullptr)
    {
      return nullptr;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
      int size = q.size();

      for (int i = 0; i < size; i++)
      {

        Node *cur = q.front();
        q.pop();

        cur->next = (i == size - 1 ? nullptr : q.front());

        if (q.empty())
        {
          cout << "#";
        }

        if (cur->left)
        {
          q.push(cur->left);
        }

        if (cur->right)
        {
          q.push(cur->right);
        }
      }
      cout << endl;
    }

    return root;
  }
};

// @lc code=end
