/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
public:

    bool is_divided(string s, string t){
        if(s.size() % t.size() != 0) return false;
        string tmp;
        for(int i = 0; i < s.size()/t.size(); i++) tmp += t;
        if(tmp == s) return true;
        else return false;
    }


    string gcdOfStrings(string s1, string s2) {
        /**
         * @brief 
         * Solution: 
         * 1. Get the sub string by checking the same part of s1, s2.
         * 2. Check the sub string, if the sub string can be divided
         *    by both s1 & s2, it must be the answer.
         * Accepted, 32ms(8.57%), 47.1MB(6.43%)
         * 
         */
        string ans, t;

        int min_s;
        if(s1.size() > s2.size()) min_s = s2.size();
        else min_s = s1.size();

        for(int i = 0; i < min_s; i++){
            if(s1[i] == s2[i]){
                t += s1[i];
                if(is_divided(s1, t) && is_divided(s2, t)){
                    ans = t;
                }
            }else{
                break;
            }
        }


        return ans;
    }
};
// @lc code=end

