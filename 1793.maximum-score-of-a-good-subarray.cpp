/*
 * @lc app=leetcode id=1793 lang=cpp
 *
 * [1793] Maximum Score of a Good Subarray
 */

// @lc code=start
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l = k, r = k, min = nums[k], ans = min;

        while(l > 0 || r < nums.size() - 1) {
            if(l == 0 || ((r < (nums.size()-1)) && (nums[r+1] > nums[l-1]))) {
                if(nums[r+1] < min) min = nums[r+1];
                r++;
                // cout << "1, ";
            }else{
                if(nums[l-1] < min) min = nums[l-1];
                l--;
                // cout << "2, ";
            }

            int len = (r-l+1);
            ans = ans > min*len ? ans:min*len;
            // cout << ans << ", " << min << ", (" << r << "," << l << ")\n";
        }

        return ans;
    }
};
// @lc code=end

