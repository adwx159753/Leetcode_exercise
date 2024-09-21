/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
/**
 * @brief 
 * [4,5,6,5]\n[2,1,2,1]
 * [1,2,3,5]\n[8,9,10,1]
 * 
 */
class Solution {
public:

    int sol(vector<pair<int,int>>& vp){
        vector<int> dp(vp.size());

        int ans = 0;
        for(int i = 0; i < vp.size(); i++){
            dp[i] = vp[i].second;
            for(int j = 0; j < i; j++){
                if(vp[i].second >= vp[j].second){
                    dp[i] = max(dp[i], vp[i].second + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        /**
         * @brief 
         * Solution: 
         * 1. Sort the player's info by ages.
         * 2. The older player should not has less score than younger player.
         *    -> The score is player score + all unconflict younger player.
         *    -> Use dynamic programming to store the maximun possible scores.
         *
         * Time Complexiy: O(n^2)
         * Accepted, 182ms(80.26%), 19.9MB(72.49%)
         * 
         */
        vector<pair<int,int>> vp;

        for(int i = 0; i < scores.size(); i++){
            vp.push_back({ages[i], scores[i]});
        }

        sort(vp.begin(), vp.end());

        // for(auto a:vp){
        //     cout << a.first << "," << a.second << endl;
        // }


        return sol(vp);
    }
};
// @lc code=end

