/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    vector<ListNode *> heap;
    void heapify(int root,int n)
    {
        int left, right, m = root;
        while (true)
        {
            left = root / 2 + 1;
            right = left + 1;
            if (left < n)
            {
                if (heap[left]->val < heap[m]->val)
                    m = left;
                if (right < n && heap[right]->val < heap[m]->val)
                    m = right;
            }

            if (m == root)
                break;
            swap(heap[m]->val, heap[root]->val);
            root = m;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        for (auto list : lists)
        {
            auto head = list;
            while (head)
            {
                heap.push_back(head);
                head = head->next;
            }
        }

        int n = heap.size();
        ListNode *ans = new ListNode(0);
        for (int root = n / 2 - 1; root >= 0; --root)
        {
            heapify(root,n);
        }

        // while (n)
        // {
        //     --n;
        //     swap(heap[n]->val, heap[0]->val);
        //     ans->next = heap[n];
        //     heapify(0,n);
        // }

        // ans->next = heap[0];

        return ans->next;
    }
};
// @lc code=end
