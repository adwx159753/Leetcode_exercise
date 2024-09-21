/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int layer = 0;
        for(auto a:logs) {
            if(a == "../") {
                if(layer > 0) layer--;
            } else if(a == "./") {
                /* */
            } else {
                layer++;
            }
            // cout << a << "," << layer << endl;
        }
        return layer;
    }
};
// @lc code=end

