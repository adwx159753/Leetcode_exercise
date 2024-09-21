/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 */

// @lc code=start

/**
 * @brief 
 * ""bb"\n"bbbbbbb""
 * 
 */
class Solution {
public:

    string expand(string& a, int& ans){
        string tmp;
        for(int i = 0; i < ans; i++) tmp+=a;
        return tmp;
    }

    int repeatedStringMatch(string a, string b) {    
        /**
         * @brief 
         * Solution: String!
         * Time Complexity: O(n+m), which n = ex.size(), and m = b.size()
         * Accepted, 8ms(74.08%), 7.1MB(60.85%)
         * 
         * 1. Expand string "a" until "a.size()" >= "b.size()"
         * 2. Use "a.find" to check if "b" is the substr of expanded "a".
         * 3. If "b" can be divided by "a", the ans should -1
         * 4. For some reason, I need to expanded "a" once more to get the 
         *    currect answer. Therefore, use goto to solve the issue.
         * 
         * 
         */
        int i = 0, ans = (b.size()/a.size())+1;
        string ex = expand(a, ans);
START_:
        size_t found = ex.find(b);
        if(found!=string::npos){
            if(found == 0 && b.size() >= a.size() && b.size() % a.size() == 0) 
                ans--;
            return ans;
        }else{
            if(ans == (b.size()/a.size())+1){
                ans++;
                ex += a;
                goto START_;
            }
        }

        return -1;
    }
};
// @lc code=end

