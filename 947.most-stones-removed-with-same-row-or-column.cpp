/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution {        
    int ans = 0;
    unordered_map<int,vector<int>> um_x;
    unordered_map<int,vector<int>> um_y;
public:

    void remove_from_stones(int& x, int& y, vector<vector<int>>& stones) {
        int index = 0;
        for(auto a:um_x[x]) {
            if(a < y)
                index++;
        }
        um_x[x].erase(um_x[x].begin() + index);

        int index_y = 0;
        for(auto a:um_x) {
            if(a.first < x) {
                index_y ++;
                index += a.second.size();
            }
        }
        um_y[y].erase(um_y[y].begin() + index_y);

        ans++;
        stones.erase(stones.begin() + index);
    }

    void remove_x(int& x, vector<vector<int>>& stones) {
        for(auto y:um_x[x]) {
            remove_from_stones(x, y, stones);
            remove_y(y, stones);
        }
    }

    void remove_y(int& y, vector<vector<int>>& stones) {
        for(auto x:um_y[y]) {
            remove_from_stones(x, y, stones);
            remove_x(x, stones);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        for(auto s:stones) {
            um_x[s[0]].push_back(s[1]);
            um_y[s[1]].push_back(s[0]);
        }

        remove_x(stones[0][0], stones);

        return ans;
    }
};
// @lc code=end

