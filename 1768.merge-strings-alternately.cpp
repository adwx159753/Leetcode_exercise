/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start

/*
""ab"\n"pqrs""
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int index1 = 0, index2 = 0;
        while(index1 < word1.size() || index2 < word2.size()) {
            if(index1 < word1.size()) {
                ans += word1[index1];
                index1++;
            }
            if(index2 < word2.size()) {
                ans += word2[index2];
                index2++;
            }
            // cout << index1 << ", " << index2 << endl;
        }
        return ans;
    }
};
// @lc code=end

