/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> ms, mt;
        int index1 = 1, index2 = 1;

        for(int i = 0; i < s.size(); i++) {
            if(ms.find(s[i]) == ms.end()) {
                ms[s[i]] = index1;
                index1++;
            }

            if(mt.find(t[i]) == mt.end()) {
                mt[t[i]] = index2;
                index2++;
            }
            
            if(ms[s[i]] != mt[t[i]]) return false;
        }

        return true;
    }
};
// @lc code=end

