/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /**
         * @brief 
         * Solution: Binary Search
         * Accepted, 0ms(100%), 9.8MB(32.24%)
         */
        if(target > nums[nums.size()-1]) return nums.size();
        else if(target < nums[0]) return 0;

        int l = 0, r = nums.size()-1;
        while(l < r){
            int m = (l+r)/2;
            if(nums[m] > target) r = m;
            else if(nums[m] < target) l = m+1;
            else return m;
            //cout << l << "," << r << "," << m << "\n";
        }

        return l;
    }
};
// @lc code=end

