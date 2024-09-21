/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        /**
         * @brief 
         * Solution: Button-Top
         * Accepted, 0ms(100%), 5.9MB(76.18%)
         * 
         */
        int tmp[3] = {0,1,1};
        if(n < 3) return tmp[n];

        int ans = 0;

        for(int i = 3; i <= n; i++){
            ans = tmp[2] + tmp[1] + tmp[0];
            tmp[0] = tmp[1];
            tmp[1] = tmp[2];
            tmp[2] = ans;
            // cout << ans << ",";
        }

        return ans;
    }
};
// @lc code=end

