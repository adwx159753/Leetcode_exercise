/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long int i = 1; i < num; i++) {
            if(i*i > num) {
                return false;
            }else if(i*i == num) {
                return true;
            }
        }
        return true;
    }
};
// @lc code=end

