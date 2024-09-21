/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    void swap(ListNode* n0, ListNode* n1, ListNode* n2){
        
        // head可能是奇數個 -> 新讀的n2可能沒有東西
        if(n2){
            // 0. n0 -> n1 -> n2 -> n3
            /* *********************** */
            // 1. n0 -> n1 -------> n3
            //                n2 -> n3
            n1->next = n2->next; 
            /* *********************** */
            // 2. n2 -> n1 -> n3
            //    n0 -> n1 -> n3
            n2->next = n1; 
            /* *********************** */
            // 3. n0 -> n2 -> n1 -> n3
            n0->next = n2;
        }
        
        // 如果n3不為null
        if(n1->next) swap(n1, n1->next, n1->next->next);
        
    }
    
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        
        ListNode* ans = new ListNode;
        swap(ans, head, head->next);
        
        return ans->next;
    }
};
// @lc code=end

