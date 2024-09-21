/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start

/**
 * @brief 
 * [-5,3,4,7,8,6,4,2,3,6,5,-9,0,3,-1,4,9,2,10,5,8,-9,-4,0,5,7,3,2,1,4,9,-5]
 * 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /**
         * @brief 
         * Solution: 
         * Time Complexity: O(n)
         * Space Complexity: O(1)
         * Accepted, 7ms(80.85%), 13.7MB(82.04%)
         * 
         * 1. Record the max number and min number.
         *    Consider the min number is the "max negative number", if we 
         *    find another negative n, the min number might become a 
         *    biggest number, vice versa, the max number can become a min
         *    number by a negative n.
         * 
         * 2. When ever we meet 0, all max and min number will become 0,
         *    0 just like the knife to cut the vector in half.
         * 
         * 3. The max just the "local max" number, therefore, we need 
         *    another variable to record the "global max" number.
         * 
         * NOTE: 
         * The max/min function can find the max/min number of an array.
         * e.g, we can find the max number as: max({1,2,3,4,5,6,...})
         * 
         */
        int maxinum = 1;
        int mininum = 1;
        int ans = -2147483647;

        for(auto n:nums){
            int tmp_max = maxinum;
            int tmp_min = mininum;

            mininum = min({n, tmp_min*n, tmp_max*n});
            maxinum = max({n, tmp_max*n, tmp_min*n});

            ans = max({n, ans, maxinum});

            // cout << n << "," 
            //      << mininum << "," 
            //      << maxinum << "," 
            //      << ans << endl;

        }


        return ans;
    }
};
// @lc code=end

