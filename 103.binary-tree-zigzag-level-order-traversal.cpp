/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        /**
         * @brief 
         * Solution: Level Order
         * Accepted, 4ms(41.42%), 12.7MB(5.81%)
         * Time Complexity: O(n)
         * Space Complexity: O(n)
         * 1. The zigzag level order traversal of a binary tree covers all the 
         *    nodes of the tree such that each level is traversed left to right 
         *    or right to left alternatively. (From workat.tech)
         * 2. Use dfs instead of stack for Level Order will be much more faster.
         * 3. When we meet next level, push back a null vector.
         * 4. When the level is odd, use insert instead of push back
         * 
         */

        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
    void dfs(TreeNode* root, int level, vector<vector<int>>& ans){
        if(!root) return ;
        if(ans.size() == level) ans.push_back({});

        if(level%2 == 0) ans[level].push_back(root->val);
        else ans[level].insert(ans[level].begin(), root->val);
        // cout << root->val << ",";

        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
    }
};
// @lc code=end

