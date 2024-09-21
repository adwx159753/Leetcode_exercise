/*
 * @lc app=leetcode id=1717 lang=cpp
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
class Solution {
private:
    int ans = 0;
public:
    void find_ab(string& s, int& x, int& y) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' && s[i+1] == 'b') {
                ans += x;
                s.erase(s.begin() + i, s.begin() + i + 1);
            }
            if(s[i] == 'b' && s[i+1] == 'a') {
                ans += y;
                s.erase(s.begin() + i, s.begin() + i + 1);
            }
        }
        cout << s << endl;
    }
    int maximumGain(string s, int x, int y) {
        if(x > y) {
            find_ab(s, x, y);
        } else {
            find_ab(s, x, y);
        }
        return ans;
    }
};
// @lc code=end

