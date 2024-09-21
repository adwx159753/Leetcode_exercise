/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
public:

    int count(int n){
        int ans = 1;
        for(int i = 9; i >= n; i--){
            ans *= i;
        }
        return ans;
    }

    void get_dp(vector<int>& dp, int n){
        dp[n] = count(10-n) + dp[n-1] + count(10-(n-1))*(n-1);
        // cout << n << ":" << dp[n] << endl;
    }

    int countNumbersWithUniqueDigits(int n) {
        /**
         * @brief 
         * Solution: math
         * Time Complexity: O(n)
         * Accepted, 0ms(100%), 5.9MB(61.31%)
         * 
         * 1. The ans will be the sum of numbers with unique digit,
         *    therefore, all number will not be use repeatly.
         * 
         *    We can count the number below 100 as:
         *    9*8 (not have 0) + 
         *    9*2 (have one 0) + 
         *    1 (only 0) = 72+18+1 = 91
         * 
         *    Then we can expand the answer to number below 1000:
         *    9*8*7 (not have 0) + 
         *    9*8*3 (have one 0) + 
         *    9*2 (have two 0) +
         *    1 (only 0) = 504+216+18+1 = 739
         * 
         *    Number below 10000:
         *    9*8*7*6 (not have 0) + 
         *    9*8*7*4 (have one 0) + 
         *    9*8*3 (have two 0) + 
         *    9*2 (have three 0) +
         *    1 (only 0) = 3024+2016+216+18+1 = 5275
         * 
         * 2. To Make the question easier, we can solve it as below:
         *    f(0) = 1
         *    f(1) = 9 + f(0) + (1-1) = 9+1 = 10
         *    f(2) = 9*8 + f(1) + 9*(2-1) = 72 + 10 + 9 = 91
         *    f(3) = 9*8*7 + f(2) + 9*8*(3-1) = 504 + 91 + 144 = 739
         *    ...
         *    f(n) = 9*8*7*...*(10-n) + f(n-1) + 9*8*7*...(10-(n-1))*(n-1)
         * 
         */

        vector<int> dp(n+1, 1);
        dp[0] = 1;

        if(n != 0){
            for(int i = 1; i <= n; i++){
                get_dp(dp, i);
            }
        }

        return dp[n];
    }
};
// @lc code=end

