/*
 * @lc app=leetcode id=1701 lang=cpp
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int cur_time = 0;
        for(auto& a:customers) {
            if(cur_time < a[0]) cur_time = a[0];
            cur_time += a[1];
            ans += (cur_time - a[0]);
        }
        return ans/customers.size();
    }
};
// @lc code=end

