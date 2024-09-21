/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:

    int subarraysDivByK(vector<int>& n, int k) {
        /**
         * @brief 
         * This Solution is from leetcode solution.
         * Time Complexity = O(n)
         * Space Complexity = O(k)
         * 
         * Consider the following situation:
         * When the remainder is the same, it means we get a divisible number.
         * Every time when we get a divisible number, the ans will add by ans+1.
         * For example: 
         * 1.   n=[5], k=5, ans=1
         *      [5]
         * 
         * 2.   n=[5,0], k=5, ans=1+2
         *      [5][5,0]
         *      [0]
         * 
         * 3.   n=[5,0,-5], k=5, ans=1+2+3
         *      [5][5,0][5,0,-5]
         *      [0][0,-5]
         *      [-5]
         * 
         * Therefore, we can use the remainder to count the answer.
         */

        int ans = 0;
        int sum = 0;
        vector<int> tmp(k);
        tmp[0] = 1;
        for(auto a:n){
            sum = (sum + a%k + k) % k;
            ans += tmp[sum];
            // cout << a << ":(" << sum << ":" << tmp[sum] << "):" << ans << endl;
            tmp[sum]++;
        }

        return ans;
    }
};
// @lc code=end

