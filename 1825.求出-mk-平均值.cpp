/*
 * @lc app=leetcode.cn id=1825 lang=cpp
 *
 * [1825] 求出 MK 平均值
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
class MKAverage
{
public:
    int m;
    int k;
    vector<int> st;

    MKAverage(int m, int k)
    {
        this->m = m;
        this->k = k;
    }

    void addElement(int num)
    {
        st.push_back(num);
    }

    int calculateMKAverage()
    {
        if (st.size() < m)
        {
            return -1;
        }

        priority_queue<int> mk_q_max;

        int count_0 = 0;
        for (int i = st.size() - 1; count_0 <= m - 1; i--)
        {
            cout << count_0 << " ";
            mk_q_max.push(st[i]);
            count_0++;
        }

        int sum = 0, i = 1, count_1 = 0;
        while (!mk_q_max.empty())
        {
            if (i > k && count_1 <= (m - 2 * k) - 1)
            {
                sum += mk_q_max.top();
                count_1++;
            }
            mk_q_max.pop();
            i++;
        }

        return sum / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
// @lc code=end
