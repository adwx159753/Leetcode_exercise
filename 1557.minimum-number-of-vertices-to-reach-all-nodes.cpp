/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

// @lc code=start

class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        /**
         * @brief 
         * Solution: Find all nodes that can't reach.
         * 1. Just consider a situation: 
         *    If a node can be reached, it shouldn't be a part of the answer.
         * 2. 
         * 
         */
        vector<bool> map(n, false);
        vector<int> ans;
        
        for(vector<int>& e:edges) 
            map[e[1]] = true;

        for(int i = 0; i < n; i++) 
            if(!map[i]) ans.push_back(i);

        return ans;
    }
};
// @lc code=end

