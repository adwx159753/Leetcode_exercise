/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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


//#define SOLUTION1
#define SOLUTION2

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
// solution2: Less Memory Solution (其實也沒有少多少)
//            solution1 : 10.7 MB
//            solution2 : 10.2 MB ~ 10.3 MB
#ifdef SOLUTION2
        
        ListNode* l = new ListNode;// < x
        ListNode* g = new ListNode;// >= x
        ListNode* l_h = l;//指向頭
        ListNode* g_h = g;
        
        while(head){
            if(head->val < x){
                l->next = head;
                l = l->next;
            }else{
                g->next = head;
                g = g->next;
            }
            head = head->next;
        }
        
        l->next = NULL;
        g->next = NULL;
        l_h = l_h->next;
        g_h = g_h->next;
        if(!l_h)
            return g_h;
        l->next = g_h;
        return l_h;

#endif

// solution1: (太冗長)
#ifdef SOLUTION1

        ListNode* ans = new ListNode;
        // 將ListNode分成less和greater兩段
        ListNode* less = new ListNode;
        ListNode* greater = new ListNode;
        // 建立兩個Node分別指向less和greater的開頭
        ListNode* begin1 = less;
        ListNode* begin2 = greater;
        // 確認各ListNode有幾個
        int l = 0;
        int g = 0;
        
        // head->val < x 放入less
        // head->val >= x 放入greater
        while(head){
            if(head->val < x){
                l++;
                less->val = head->val;
                
                ListNode* next = new ListNode;
                less->next = next;
                less = less->next;
            }else{
                g++;
                greater->val = head->val;
                
                ListNode* next = new ListNode;
                greater->next = next;
                greater = greater->next;
            }
            head = head->next;
        }
        // 建一個tmp，用來將less和greater合併
        ListNode* tmp = new ListNode;
        // ans指向tmp的頭
        ans = tmp;
        while(l > 0 || g > 0){
            if(l > 0){
                l--;
                tmp->val = begin1->val;
                begin1 = begin1->next;
            }else{
                g--;
                tmp->val = begin2->val;
                begin2 = begin2->next;
            }
            // greater內還有東西 or 沒有greater但有less
            // 新建一個Node
            if(g > 0 || (l > 0 && g == 0)){
                ListNode* next = new ListNode;
                tmp->next = next;
                tmp = tmp->next;
            }
        }
        
        return ans;
#endif
    }
};
// @lc code=end

