/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
class Solution {
public:
    double average(vector<int>& salary) {
        int max = 0, min = 1000000;
        double ans;

        for(int v:salary) {
            ans += v;
            if(v > max) max = v;
            if(v < min) min = v;
        }

        return (ans-max-min)/(salary.size()-2);
    }
};
// @lc code=end

