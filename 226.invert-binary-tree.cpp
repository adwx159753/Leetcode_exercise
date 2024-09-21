/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    void swap(TreeNode* root){
        if(!root) return ;
        TreeNode* Temp = root->left;
        root->left = root->right;
        root->right = Temp;
        swap(root->left);
        swap(root->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        /**
         * @brief
         * Solution: DFS, and Swap the children
         * Accepted, 0ms(100%), 9.9MB(6.37%)
         */
        swap(root);
        return root;
    }
};
// @lc code=end

