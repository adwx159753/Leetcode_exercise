/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num = 0;
        int ans = 0;
        vector<pair<int, int>> vp;
        pair<int, int> tmp = {0, 0};
        for(auto a:nums){
            if(tmp.first != a) {
                vp.push_back(tmp);
                tmp.first = a;
                tmp.second = 1;
            } else {
                tmp.second++;
            }
        } vp.push_back(tmp);

        for(auto a:vp) {
            // cout << a.first << "," << a.second << endl;
            if(max_num < a.first) {
                max_num = a.first;
                ans = a.second;
            } else if (max_num == a.first){
                ans = max(ans, a.second);
            }
        }

        return ans;
    }
};
// @lc code=end

