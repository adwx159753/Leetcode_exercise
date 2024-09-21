/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:
    /**
     * @brief Find the parent of each node.
     * 
     * @param root 
     * @param vp 
     */
    void ancient(TreeNode* root, map<TreeNode*, TreeNode*>& m) {
        // use map to store all parent of each node.
        if(root->left) {
            m[root->left] = root;
            ancient(root->left, m);
        }
        if(root->right) {
            m[root->right] = root;
            ancient(root->right, m);
        }
    }

    void solution(TreeNode* t, map<TreeNode*, TreeNode*>& m, int k, vector<int>& ans) {
        // cout << t->val << ", " << k << "\n";

        // find the ans
        if(k == 0) {
            ans.push_back(t->val);
            return ;
        }

        // Mark the visited node
        t->val = -1;

        // visit all nodes.
        if(t->left != nullptr)
            if(t->left->val >= 0)
                solution(t->left, m, k-1, ans);
        if(t->right != nullptr)
            if(t->right->val >= 0)
                solution(t->right, m, k-1, ans);
        if(m[t] != nullptr)
            if(m[t]->val >= 0)
                solution(m[t], m, k-1, ans);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        /**
         * @brief 
         * Solution:
         * 1. Make a map to store all parent of each nodes.
         * 2. DFS, but search all nodes by 3 direction (parent/left/right).
         * 3. Avoid to check the same node twice, mark the visited node.
         * 
         * Time Complexity: O(n*logn) (n node search in map structure)
         * 
         * [0,null,1,null,2,null,3,null,4]\n0\n2
         * 
         */
        map<TreeNode*, TreeNode*> m;
        vector<int> ans;

        ancient(root, m);
        solution(target, m, k, ans);

        return ans;
    }
};
// @lc code=end

