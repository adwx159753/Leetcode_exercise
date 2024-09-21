/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
class Solution {
private:

    void dfs(vector<int>& ans, int tmp, int& n){
        if(tmp > n) return ;
        // cout << tmp << " ";
        ans.push_back(tmp);
        for(int i = 0; i < 10; i++){
            dfs(ans, tmp*10 + i, n);
        }
    }

public:

    vector<int> lexicalOrder(int n) {
        /**
         * @brief 
         * Solution: DFS
         * Time Complexity: O(n) -> all number
         * Space Complexity: O(n) -> all number
         * Acceted, 16ms(52.48%), 11.3MB(62.17%).
         * 
         * 1. Consider a tree as below:
         * 
         *                           root(NULL)
         *                           ↙
         *                   {1,2,3,4,5,6,7,8,9} (first level)
         *                   ↙
         *          {0,1,2,3,4,5,6,7,8,9} (second level)
         *          ↙ 
         * {0,1,2,3,4,5,6,7,8,9} (third level)
         *     
         *    Except the first level, all node has 10 children.
         *    Now we sort this tree as inorder:
         *    {1,10,100,101,102,103,...,109,
         *       11,110,111,112,113,...,119,
         *       12,120,121,122,123,...,129,
         *       ...
         *       ...
         *       ...
         *       99,990,991,992,993,...,999}
         *    
         * 2. Now consider the question, e.g. n = 999
         *    {1,10,100,101,102,103,...,109,
         *       11,110,111,112,113,...,119,
         *       12,120,121,122,123,...,129,
         *       ...
         *       ...
         *       ...
         *       99,990,991,992,993,...,999}
         * 
         *    As we can see, the number is sorted as inorder of the tree. 
         *    
         * 
         */
        vector<int> ans;        
        
        for(int i = 1; i < 10; i++)
            dfs(ans, i, n);

        return ans;
    }
};
// @lc code=end

