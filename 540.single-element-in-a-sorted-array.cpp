/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        /**
         * @brief 
         * Solution: Binary Search
         * Accepted, 30ms(54.93%), 22.3MB(62.93%)
         * Time Compleixty: O(logn)
         * 1. Consider the list = {1,1,2,3,3,4,4,5,5}
         *    If we check the middle of the list and look up the neighbor, we 
         *    will get the direction of the target.
         *    => 1,1,2,3,(3),4,4,5,5
         *    Observe the neighber of (3), if the neighbor doesn't equal the 
         *    middle number, the target must at the opposite direction.
         * 
         * 2. Now Consider the list = {1,1,2,3,3,4,4,5,5,6,6}
         *    If we check the middle of the list 
         *    => 1,1,2,3,3,(4),4,5,5,6,6
         *    Observe the neighbor of (4), the rule is totally contrast, 
         *    therefore, when m%2 == 1, we should m should minus 1 to consist
         *    with the rule of 1.
         *    
         * 3. Because the element will appear exactly twice, we should add 2
         *    every times when we changing the min limit.
         * 
         */
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int m = (l+r)/2;
            if(m%2 == 1) m--;
            // cout << l << "," << r << "," << m << endl;
            if(nums[m] == nums[m+1]) l = m+2;
            else r = m;
        }
        // cout << l << "," << r << endl;
        return nums[l];
    }
};
// @lc code=end

