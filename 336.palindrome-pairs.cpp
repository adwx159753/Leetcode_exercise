/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
class Solution {
public:
    bool is_pal(string& s1, string& s2){
        string s3 = s1 + s2;
        for(int i = 0; i < s3.size()/2; i++)
            if(s3[i] != s3[s3.size()-1-i]) return false;
        return true;
    }

    /**
     * @brief 
     * Solution1: Brute
     * Time Complexity: O(n^2), It cost Sig(n-1) = (n-1)*(n-2)/2
     * TLE, 81/136 cases passed (N/A)
     */
    vector<vector<int>> solution1(vector<string>& words){
        vector<vector<int>> ans;

        for(int i = 0; i < words.size()-1; i++){
            for(int j = i+1; j < words.size(); j++){
                // cout << i << j << endl;
                if(is_pal(words[i], words[j])){
                    ans.push_back({i,j});
                }
                if(is_pal(words[j], words[i])){
                    ans.push_back({j,i});
                }
            }
        }
        return ans;
    }

    /**
     * @brief 
     * Solution2: Trie (Dictionary Tree)
     */
    vector<vector<int>> solution2(vector<string>& words){
        /* I Don't Understand */
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        return solution1(words);
    }
};
// @lc code=end

