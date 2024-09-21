/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Solution1: read the whole vector nums, record the color via another vectors, and combine them.
        // Time Complexity: O(n) 
        // Status: Accepted, 0ms(100.00%), 8.6MB(23.72%)
        // Comparing with the library's sort function, our time complexity is better than O(n*log2(n)), but the memory used might be worse.
        // Decreasing memory: Record the number of color instead of record the actual number, 
        // time complexity will become O(2n), but it still better than the library's sort function.
        
        vector<int> ans;
        vector<int> red;  // 0
        vector<int> white;// 1
        vector<int> blue; // 2
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) red.push_back(0);
            else if(nums[i] == 1) white.push_back(1);
            else blue.push_back(2);
        }
        
        ans.insert(ans.end(), red.begin(), red.end());
        ans.insert(ans.end(), white.begin(), white.end());
        ans.insert(ans.end(), blue.begin(), blue.end());
        
        nums=ans;
    }
};
// @lc code=end

