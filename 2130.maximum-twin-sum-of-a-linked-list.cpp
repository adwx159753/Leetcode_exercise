/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
class Solution {
public:
    void build(ListNode* head, vector<int>& v) {
        if(head == nullptr) return ;
        // cout << head->val << "," ;
        v.push_back(head->val);
        build(head->next, v);
    }
    int pairSum(ListNode* head) {
        int ans = 0;
        vector<int> v;
        build(head, v);

        for(int i = 0; i < v.size()/2; i++) {
            int tmp = (v[i] + v[v.size() - 1 - i]);
            // cout << v[i] << " + " << v[v.size() - 1 - i] << " = " << tmp << endl;
            if(tmp > ans) ans = tmp;
        }

        return ans;
    }
};
// @lc code=end

