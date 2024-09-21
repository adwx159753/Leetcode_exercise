/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        int cur_node = k-1;
        for(int i = 0; i < n; i++) v.push_back(i+1);

        while(v.size() > 1) {
            cur_node %= v.size();
            // cout << "erase:" << cur_node << ":" << v[cur_node] << endl;
            v.erase(v.begin() + cur_node);
            cur_node += (k-1);
        }

        return v[0];
    }
};
// @lc code=end

