/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
#define SOLUTION_2
//#define SOLUTION_1
class Solution {
public:
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
#ifdef SOLUTION_2
        // Solution 2: 串起來，再看k決定誰當頭
        // Status: Accepted, 11ms(65.09%), 11.8MB(54.77%)
        
        int size = 2;
        // 找到倒數第2
        ListNode* second_last = head;
        while(second_last->next->next){
            second_last = second_last->next;
            size++;
        }
        // 找到最後一個
        ListNode* last = second_last->next;
        // 最後一個連到頭
        second_last->next->next = head;
        // 看第幾個要當頭
        size = size - k%size - 1;
        // 找到斷點
        while(size > 0){
            size--;
            head=head->next;
        }
        // 找到新的頭
        ListNode* ans = head->next;
        // 尾巴斷掉
        head->next = nullptr;
        
        return ans;
#endif
        
        
#ifdef SOLUTION_1
        // Solution 1: 轉起來 
        // Time Complexity = O(n*k) Status: TLE
        while(k > 0){
            k--;
            ListNode* second_last = head;
            while(second_last->next->next) second_last = second_last->next;
            ListNode* last = second_last->next;
            second_last->next->next = head;
            second_last->next = nullptr;
            head = last;
        }
        return head;
#endif
    }
};
// @lc code=end

